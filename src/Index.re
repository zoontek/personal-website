[%bs.raw {|require('normalize.css')|}];
[%bs.raw {|require('./static/css/reset.css')|}];

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
  global("body", [fontFamily(Js.Array.join(fonts))]),
);

ReactDOMRe.renderToElementWithId(<App />, "root");
