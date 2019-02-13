const path = require("path");
const fs = require("fs");
const HtmlWebpackPlugin = require("html-webpack-plugin");
const MiniCssExtractPlugin = require("mini-css-extract-plugin");
const StyleExtHtmlWebpackPlugin = require("style-ext-html-webpack-plugin");

const isProduction = process.env.NODE_ENV === "production";
const outputDir = path.join(__dirname, "build");

if (isProduction) {
  fs.mkdirSync(outputDir);
}

const fileLoaderOptions = {
  name: isProduction
    ? path.join("static", "media", "[name].[hash].[ext]")
    : "[path][name].[ext]",
};

const getFaviconHtml = isProduction
  ? require("./generate-favicon")
  : () => Promise.resolve("");

module.exports = getFaviconHtml(outputDir).then(faviconHtml => ({
  entry: path.join(__dirname, "src", "Index.bs.js"),
  mode: isProduction ? "production" : "development",
  devtool: isProduction ? "source-map" : "cheap-module-eval-source-map",

  output: {
    path: outputDir,
    sourceMapFilename: "bundle.[hash].js.map",
    filename: "bundle.[hash].js",
  },

  module: {
    rules: [
      {
        test: /\.css$/,
        use: [MiniCssExtractPlugin.loader, "css-loader"],
      },
      {
        test: /\.(jpg|png|svg)$/,
        use: {
          loader: "file-loader",
          options: fileLoaderOptions,
        },
      },
      {
        test: /\.(woff|woff2)$/,
        use: {
          loader: "file-loader",
          options: fileLoaderOptions,
        },
      },
    ],
  },

  plugins: [
    new HtmlWebpackPlugin({
      template: path.join("src", "index.html"),
      inject: true,
      faviconHtml,
      contentHtml: isProduction ? require("./__prerender").html : "",
      minify: isProduction && {
        collapseWhitespace: true,
        removeComments: true,
        removeRedundantAttributes: true,
        removeScriptTypeAttributes: true,
        removeStyleLinkTypeAttributes: true,
        useShortDoctype: true,
      },
    }),
    new MiniCssExtractPlugin(),
    new StyleExtHtmlWebpackPlugin({
      minify: isProduction,
    }),
  ],

  devServer: {
    compress: true,
    port: process.env.PORT || 8000,
    contentBase: outputDir,
    historyApiFallback: true,
  },
}));
