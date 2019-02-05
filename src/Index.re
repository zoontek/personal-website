open Belt;

[%bs.raw {|require('normalize.css')|}];
[%bs.raw {|require('./static/css/global.css')|}];

[@bs.module]
external quasimodaRegular: string = "./static/fonts/Quasimoda-Regular.woff";
[@bs.module]
external quasimodaBold: string = "./static/fonts/Quasimoda-Bold.woff";

let fonts = [|
  "Quasimoda",
  "-apple-system",
  "BlinkMacSystemFont",
  "\"Segoe UI\"",
  "Helvetica",
  "Arial",
  "sans-serif",
  "\"Apple Color Emoji\"",
  "\"Segoe UI Emoji\"",
  "\"Segoe UI Symbol\"",
|];

let bodyFontFamily =
  Array.reduceWithIndex(fonts, "", (acc, font, index) =>
    acc ++ font ++ (index !== Array.size(fonts) - 1 ? "," : "")
  );

Css.(
  fontFace(
    ~fontFamily="Quasimoda",
    ~src=[url(quasimodaRegular)],
    ~fontStyle=`normal,
    ~fontWeight=`num(400),
    (),
  ),
  fontFace(
    ~fontFamily="Quasimoda",
    ~src=[url(quasimodaBold)],
    ~fontStyle=`normal,
    ~fontWeight=`num(700),
    (),
  ),
  global("body", [fontFamily(bodyFontFamily)]),
);

ReactDOMRe.renderToElementWithId(<App />, "root");
