type headingLevel =
  | H1
  | H2;

let component = React.statelessComponent("Title");

module Styles = {
  open Css;

  let base =
    style([
      fontFamily("PlayfairDisplay"),
      fontWeight(`num(700)),
      color(Theme.titleColor),
      lineHeight(`abs(1.2)),
    ]);

  let withFontSize = pxValue =>
    merge([base, style([fontSize(pxValue->px)])]);
};

let make = (~level, children) => {
  ...component,
  render: _self => {
    switch (level) {
    | H1 => <h1 className={Styles.withFontSize(48)}> ...children </h1>
    | H2 => <h2 className={Styles.withFontSize(32)}> ...children </h2>
    };
  },
};
