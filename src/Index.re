open Belt;

[%bs.raw {|require('normalize.css')|}];
[%bs.raw {|require('./static/css/global.css')|}];

[@bs.module]
external quasimodaRegular: string = "./static/fonts/quasimoda_regular.woff";
[@bs.module]
external quasimodaBold: string = "./static/fonts/quasimoda_bold.woff";

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

let lastIndex = Array.size(fonts) - 1;

let fontFamily =
  Array.reduceWithIndex(fonts, "", (acc, font, index) =>
    acc ++ font ++ (index !== lastIndex ? "," : "")
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
  global("body", [fontFamily(fontFamily)]),
);

ReactDOMRe.renderToElementWithId(<App />, "root");
