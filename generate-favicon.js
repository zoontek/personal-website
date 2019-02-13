const path = require("path");
const fs = require("fs");
const favicons = require("favicons");
const pkg = require("./package.json");

const faviconSrc = path.join(__dirname, "favicon.png");

const config = {
  path: "/",
  appShortName: "Mathieu Acthernoene",
  appName: "Mathieu Acthernoene",
  appDescription: "front-end and mobile developer",
  developerName: pkg.author,
  developerURL: "https://github.com/zoontek",
  dir: "auto",
  lang: "en-US",
  background: "#d3e8e1",
  theme_color: "#d3e8e1",
  appleStatusBarStyle: "default",
  display: "browser",
  orientation: "portrait",
  scope: "/",
  start_url: "/",
  version: pkg.version,
  logging: false,
  pixel_art: false,
  loadManifestWithCredentials: false,
  icons: {
    android: true,
    appleStartup: false,
    appleIcon: true,
    coast: false,
    favicons: true,
    firefox: true,
    windows: false,
    yandex: false,
  },
};

module.exports = outputDir =>
  favicons(faviconSrc, config, (err, res) => {
    if (err) {
      return console.error(err.message);
    }

    res.images.forEach(({ contents, name }) => {
      fs.writeFile(
        path.join(outputDir, name),
        contents,
        "binary",
        err => err && console.error(err.message),
      );
    });

    res.files.forEach(({ contents, name }) => {
      fs.writeFile(
        path.join(outputDir, name),
        contents,
        "utf-8",
        err => err && console.error(err.message),
      );
    });

    return res.html.join("");
  });
