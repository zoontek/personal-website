const path = require("path");

const CopyWebpackPlugin = require("copy-webpack-plugin");
const HtmlWebpackPlugin = require("html-webpack-plugin");
const MiniCssExtractPlugin = require("mini-css-extract-plugin");
const StyleExtHtmlWebpackPlugin = require("style-ext-html-webpack-plugin");

const isProduction = process.env.NODE_ENV === "production";
const outputDir = path.join(__dirname, "build");
const mediaDir = isProduction
  ? path.join("static", "media", "[name].[hash].[ext]")
  : "[path][name].[ext]";

module.exports = {
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
          options: { name: mediaDir },
        },
      },
      {
        test: /\.(woff|woff2)$/,
        use: {
          loader: "file-loader",
          options: { name: mediaDir },
        },
      },
    ],
  },
  plugins: [
    new CopyWebpackPlugin([path.join(__dirname, "public")]),
    new HtmlWebpackPlugin({
      template: path.join("public", "index.html"),
      inject: true,
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
};
