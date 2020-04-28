# -*- coding: utf-8 -*-
import requests
import base64
import json
import random
import math
from threading import Thread

def read_data(file_name):
        content = fp.read()
        content_en = base64.urlsafe_b64encode(content)
        content_str = str(content_en, encoding = "ascii")
        return content_str
def create_server_num():
        server_num = random.randint(0,2)
        return server_num
def up_load(conn_meta, server_set, str_begin, str_end, content, f_name, se_begin, chunk_num):
        print("string:",len(content),"str_begin:",str_begin,"str_end",str_end)
        for i in range(str_begin, str_end,1024):
            print("string:",len(content), i, "<- str_begin:",str_begin,"str_end",str_end)
        for i in range(str_begin, str_end,1024):
                conn_num = create_server_num()
                conn_server = server_set[conn_num]
                content_chunk = content[i:i+1024]
                print("content_length:",len(content_chunk),se_begin)
                #upload_chunk(conn_server, content_chunk, f_name, se_begin)
                #upload_meta(conn_meta, f_name, chunk_num, se_begin, server_set, conn_num)
                se_begin += 1

def upload_chunk(conn_server, chunk, file_name, sequence):
        chunk_data['chunk'] = chunk
        chunk_data['filename'] = file_name
        chunk_data['sequence'] = sequence
        chunk_data_json = json.dumps(chunk_data)
        r = requests.post(conn_server, data=chunk_data_json, headers=headers)
        print(r)

def upload_meta(conn_meta, file_name, chunk_num, sequence, server_set, server_num):
        meta_data['filename'] = file_name
        meta_data['chunknum'] = chunk_num
        meta_data['sequence'] = sequence
        meta_data['conn_server'] = server_set[server_num]
        meta_data['server_num'] = server_num
        meta_data_json = json.dumps(meta_data)
        r = requests.post(conn_meta, data=meta_data_json, headers=headers)
        print(r)


headers = {"Content-Type": "application/x-www-form-urlencoded",
           'User-Agent': 'Mozilla/5.0 (X11; Ubuntu; Linux x86_64; rv:22.0) Gecko/20100101 Firefox/22.0'}
chunk_data = {}
meta_data = {}
server_set = ['http://127.0.0.1:5000/','http://127.0.0.1:5001/','http://127.0.0.1:5002/']
conn_meta = 'http://127.0.0.1:5004/'
TH_NUM = 3
chunk_num = 0
cur_con = 0
cur_sq = 0

file_name = 'manim_docker_diagram.png'
fp = open(file_name,'rb')
str_key = input("请输入文件名：")
content_str = read_data(file_name)      #读文件
print(len(content_str))

general_th_pro = math.floor(len(content_str)/TH_NUM)    #计算每个线程处理多少字节并有多少包
if len(content_str)%TH_NUM == 0:
        last_th_pro = general_th_pro
else:
        last_th_pro = general_th_pro+1
general_chunk_num = math.ceil(general_th_pro/1024)
last_chunk_num = math.ceil(last_th_pro/1024)

for i in range(0,TH_NUM-1):     #计算包总数
        chunk_num += general_chunk_num
chunk_num += last_chunk_num
print(chunk_num)

for i in range(0,TH_NUM):       #创建多线程
        cur_con = i*general_th_pro
        cur_sq = i*general_chunk_num
        if i == TH_NUM-1:
                content = content_str[cur_con:cur_con+last_th_pro]
                print(len(content))
                th = Thread(target=up_load, args=(conn_meta, server_set, cur_con, cur_con+last_th_pro, content, str_key, cur_sq, chunk_num))
                th.start()
        else:
                content = content_str[cur_con:cur_con+general_th_pro]
                print(len(content))
                th = Thread(target=up_load, args=(conn_meta, server_set, cur_con, cur_con+general_th_pro, content, str_key, cur_sq, chunk_num))
                th.start()
'''for index in range(0,len(content_str),1024):
        server_num = random.randint(0,2)
        conn_server = server_set[server_num]
        chunk_data['chunk'] = content_str[index:index+1024]
        chunk_data['filename'] = str_key
        chunk_data['sequence'] = int(index/1024)
        chunk_data_json = json.dumps(chunk_data)

        meta_data['filename'] = str_key
        meta_data['chunknum'] = chunk_num
        meta_data['sequence'] = int(index/1024)
        meta_data['conn_server'] = conn_server
        meta_data['server_num'] = server_num
        meta_data_json = json.dumps(meta_data)
        
        r2 = requests.post(conn_meta, data=meta_data_json, headers=headers)
        r1 = requests.post(conn_server, data=chunk_data_json, headers=headers)
        print(r1)
        print(r2)'''