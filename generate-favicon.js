const fs = require("fs");
const pkg = require("./package.json");
const favicons = require("favicons");

const source = "./favicon.png";

const configuration = {
  path: "/", // Path for overriding default icons path. `string`
  appName: "Mathieu Acthernoene", // Your application's name. `string`
  appShortName: "Mathieu Acthernoene", // Your application's short_name. `string`. Optional. If not set, appName will be used
  appDescription: "front-end and mobile developer", // Your application's description. `string`
  developerName: "Mathieu Acthernoene", // Your (or your developer's) name. `string`
  developerURL: "https://github.com/zoontek", // Your (or your developer's) URL. `string`
  dir: "auto", // Primary text direction for name, short_name, and description
  lang: "en-US", // Primary language for name and short_name
  background: "#d3e8e1", // Background colour for flattened icons. `string`
  theme_color: "#d3e8e1", // Theme color user for example in Android's task switcher. `string`
  appleStatusBarStyle: "default", // Style for Apple status bar: "black-translucent", "default", "black". `string`
  display: "browser", // Preferred display mode: "fullscreen", "standalone", "minimal-ui" or "browser". `string`
  orientation: "portrait", // Default orientation: "any", "natural", "portrait" or "landscape". `string`
  scope: "/", // set of URLs that the browser considers within your app
  start_url: "/", // Start URL when launching the application from a device. `string`
  version: pkg.version, // Your application's version string. `string`
  logging: false, // Print logs to console? `boolean`
  pixel_art: false, // Keeps pixels "sharp" when scaling up, for pixel art. Only supported in offline mode.
  loadManifestWithCredentials: false, // Browsers don't send cookies when fetching a manifest, enable this to fix that. `boolean`
  icons: {
    android: true, // Create Android homescreen icon. `boolean` or `{ offset, background, mask, overlayGlow, overlayShadow }`
    appleIcon: true, // Create Apple touch icons. `boolean` or `{ offset, background, mask, overlayGlow, overlayShadow }`
    appleStartup: false, // Create Apple startup images. `boolean` or `{ offset, background, mask, overlayGlow, overlayShadow }`
    coast: false, // Create Opera Coast icon. `boolean` or `{ offset, background, mask, overlayGlow, overlayShadow }`
    favicons: true, // Create regular favicons. `boolean` or `{ offset, background, mask, overlayGlow, overlayShadow }`
    firefox: true, // Create Firefox OS icons. `boolean` or `{ offset, background, mask, overlayGlow, overlayShadow }`
    windows: false, // Create Windows 8 tile icons. `boolean` or `{ offset, background, mask, overlayGlow, overlayShadow }`
    yandex: false, // Create Yandex browser icon. `boolean` or `{ offset, background, mask, overlayGlow, overlayShadow }`
  },
};

favicons(source, configuration, (error, res) => {
  if (error) {
    return console.error(error.message);
  }

  res.images.forEach(({ contents, name }) =>
    fs.writeFile(
      __dirname + "/public/" + name,
      contents,
      "binary",
      err => !err && console.log(`✅ ${name}`),
    ),
  );

  res.files.forEach(({ contents, name }) =>
    fs.writeFile(
      __dirname + "/public/" + name,
      contents,
      "utf-8",
      err => !err && console.log(`✅ ${name}`),
    ),
  );

  const head = res.html.reduce((acc, h) => acc + h + "\r\n", "");
  console.log("HTML:\r\n\r\n");
  console.log(head);
});
