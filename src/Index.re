[%bs.raw {|require('normalize.css')|}];

[@bs.module]
external quasimodaRegular: string = "./assets/fonts/quasimoda_regular.woff";
[@bs.module]
external quasimodaBold: string = "./assets/fonts/quasimoda_bold.woff";

Css.(
  fontFace(
    ~fontFamily="Quasimoda",
    ~src=[url(quasimodaRegular)],
    ~fontStyle=normal,
    ~fontWeight=`num(400),
    (),
  )
);

Css.(
  fontFace(
    ~fontFamily="Quasimoda",
    ~src=[url(quasimodaBold)],
    ~fontStyle=normal,
    ~fontWeight=`num(700),
    (),
  )
);

Css.(global("body", [fontFamily("Quasimoda"), fontWeight(bold)]));

ReactDOMRe.renderToElementWithId(<App />, "root");
