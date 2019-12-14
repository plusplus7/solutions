const path = require('path');

module.exports = {
    entry: "./main.ts",
    output: {
        path: path.resolve(__dirname, 'public'),
        filename: "bundle.js"
    },
    resolve:{
        extensions: ['.ts', '.glsl']
    },
    module: {
        strictExportPresence: true,
        rules:[
            {
                test: /\.(ts|tsx)$/,
                loader: require.resolve('ts-loader'),
                exclude: /node_modules/,
            },
            {
                test: /\.glsl$/,
                loader: 'ts-shader-loader'
            }
        ],
    },
};