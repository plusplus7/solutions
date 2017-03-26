# Make Power BI Dashboard with Different Azure Data Sources

## Overview

## Data definition

Let's simplify our scenario, we have a website, providng documents downloading service. Our documents are kept in Azure Document DB with JSON structure and download histories are kept in Azure SQL Database. 

Every document has a unique document ID. Since we may update the document,  each document would have several versions. Each time document is updated, we give it a different version ID. Besides that, according to different cultures, the title and content are different in one document version. For example, the document has an English version and a Spanish version, and document titles in these two versions are apparently different when displayed.

```json
{
    "Id":  "6ce3c6ab-4718-493d-a880-9a13e2907fd1", // DocumentId
    "Versions": [
        {
            "Id": "49dc3432-7e9e-4131-a11b-8b5e05b751e3", // VersionId
            "DocumentId": "6ce3c6ab-4718-493d-a880-9a13e2907fd1",
            "Title": [
                {
                    "CultureName": "en-US",
                    "DisplayValue": "Get started with Azure Key Vault"
                },
                {
                    "CultureName": "es-mx",
                    "DisplayValue": "Comience con Azure Key Vault"
                }
            ],
            "Content": [
                ...
            ],
            ...
        }
    ]
}
```

As you can see here, we have "Id" property, which represents the document ID, and "Versions" property, which contains a lot of version objects. Each version object has a unique version ID. The "Title" property in version object is a list of title object, which tells us what value should be displayed in that culture.

The download history is kept in a simple single table, keeping track of what document ID and version ID of document was downloaded, and when it was downloaded.

```sql
CREATE TABLE [dbo].[DownloadHistory] (
    [Id]              UNIQUEIDENTIFIER NOT NULL,
    [WhenDownloaded]  DATETIME         NOT NULL,
    [DocumentId]      UNIQUEIDENTIFIER NOT NULL,
    [VersionId]       UNIQUEIDENTIFIER NOT NULL,
    PRIMARY KEY CLUSTERED ([Id] ASC)
);
```

## Goal

What I am going to do here is to create a Power BI dashboard, which imports data from both SQL database and Document DB, and then joins these data together to present a friendly report, but not ugly GUID. More specifically, the dash board would present the number of download request per hour and the most popular documents.


![](http://7xlt42.com1.z0.glb.clouddn.com/goal_picture.jpg-fullpercent)

## Data Importing 

First, we need to import data from SQL database and Document DB in Power BI. Make sure you have valid credentials and read access to SQL DB and Doc DB.

![](http://7xlt42.com1.z0.glb.clouddn.com/data_importing.jpg-fullpercent)

After connecting to data sources, we can see two fields('DownloadHistory' and 'Query 1') at this page. I prefer to rename the 'Query 1' field to 'DocumentVersions'.

![](http://7xlt42.com1.z0.glb.clouddn.com/after_importing.jpg-fullpercent)


## Line Chart

As you can see, the time of downloading is recorded in the 'DownloadHistory' table and the time is accurate to seconds. But actually, I just want to count requests by hour. So I'm going to write a query to get the start of hour of the downloading time.

Click the Edit Queries to open Query Editor

![](http://7xlt42.com1.z0.glb.clouddn.com/start_of_hour.jpg-fullpercent)

Click 'WhenDownloaded' column, which means you are going to add a new column based on this column.

![](http://7xlt42.com1.z0.glb.clouddn.com/add_time_column.jpg-fullpercent)

After these steps, you will see a new column called 'StartOfHour' created and the time is accurate to hours. Go back to Home page, and click 'Close & Apply'.

![](http://7xlt42.com1.z0.glb.clouddn.com/close_and_apply.jpg-fullpercent)

Now we are able to calculate the request of every hour. Let's back to the Data view.
Click New Table to create a result table of requests per hour.
Initialize the table with DAX function using 'StartOfHour' column we created just now.

This DAX function is going to get distinct values of column.

```dax
Request per hour = SUMMARIZE(DownloadHistory, DownloadHistory[StartOfHour])
```

![](http://7xlt42.com1.z0.glb.clouddn.com/request_per_hour.jpg-fullpercent)

Click New Column and write DAX function to calculate the requests of every hour.

```dax
Count of hour = COUNTROWS(FILTER('DownloadHistory', DownloadHistory[StartOfHour]='Request per hour'[StartOfHour]))
```

The function FILTER will scan the whole table (DownloadHistory), pick out all the rows that satisfy the following condition into a temporary table. So here when we are trying to count the request of some hour, we should pick out all the rows with StartOfHour match to the hour that we want.

The function COUNTROWS will return the number of rows in that table.

OK. Let's go back to Report view and make a line chart.

![](http://7xlt42.com1.z0.glb.clouddn.com/line_chart.jpg-fullpercent)

And here, we got what we want.

## Joining Data

Now we are going to calculate the most popular documents.

First of all, we have to expand the columns of DocumentVersions query, because all the document version data are JSON structure.

Go to Data view and open Edit Queries panel.

If the object in JSON is a dictionary, the Power BI would let you select the property that you want to expand.

Select all the columns that you are interested in.

![](http://7xlt42.com1.z0.glb.clouddn.com/open_edit.jpg-fullpercent)

In our scenario, we should select Id and Versions.

![](http://7xlt42.com1.z0.glb.clouddn.com/expanded_dict.jpg-fullpercent)

If the object in JSON is a list, we got two choice. We can expand the objects in the list to new rows, and we can also just extract the objects with delimiter to seperate each objects.

When expanding list object into new rows, the size of rows in our table would increase according to the size of list.

For example,

    | A | [a, b, c] |

would be expanded like,

    | A | a |
    | A | b |
    | A | c |

Here we want to expand versions into new rows, because we have different cultures and different display values. We want to get that value.

![](http://7xlt42.com1.z0.glb.clouddn.com/expand_list.jpg-fullpercent)

Then, the DocumentVersions table would be expanded to this. Close and apply.

Every document is expanded into two rows, because we have two different cultures (en-US, es-mx) of document version title.

Back to Data view. Create a new result table called Requests per document and initialize table with DAX function:

```DAX
Requests per document = SUMMARIZE(ActionHistory, ActionHistory[DocumentId], ActionHistory[VersionId])
```

![](http://7xlt42.com1.z0.glb.clouddn.com/docid_verid.jpg-fullpercent)

Add a column called Requests to calculate the number of downloading request of this document, just like when we were calculating requests per hour.

```DAX
Requests = COUNTROWS(FILTER(ActionHistory, 'Requests per document'[DocumentId]=ActionHistory[DocumentId] && 'Requests per document'[VersionId]=ActionHistory[VersionId]))
```

![](http://7xlt42.com1.z0.glb.clouddn.com/docid_verid_requests.jpg-fullpercent)

Add a column called Title, which is the title of this document. Write a DAX function to look up the value of title based on the DocumentVersions table we expanded just now.

```DAX
Title = LOOKUPVALUE(DocumentVersions[Document.Versions.Title.DisplayValue], DocumentVersions[Document.Id], 'Requests per document'[DocumentId], DocumentVersions[Document.Versions.Id], 'Requests per document'[VersionId], DocumentVersions[Document.Versions.Title.CultureName], "en-US")
```

![](http://7xlt42.com1.z0.glb.clouddn.com/docid_verid_requests_title.jpg-fullpercent)

Back to the Report view and create a simple table based on the result table.

![](http://7xlt42.com1.z0.glb.clouddn.com/final_goal.jpg-fullpercent)

And now we get what we want!