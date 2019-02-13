const path = require("path");
const MiniCssExtractPlugin = require("mini-css-extract-plugin");

const fileLoaderOptions = {
  name: path.join("static", "media", "[name].[hash].[ext]"),
  emitFile: false,
};

module.exports = {
  entry: path.join(__dirname, "src", "Prerender.bs.js"),
  mode: "production",
  target: "node",

  output: {
    path: path.join(__dirname, "__prerender"),
    filename: "index.js",
    libraryTarget: "commonjs",
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

  plugins: [new MiniCssExtractPlugin()],
};
