open Css;

[@bs.module]
external karmillaRegular: string = "../static/fonts/Karmilla-Regular.woff";
[@bs.module]
external karmillaBold: string = "../static/fonts/Karmilla-Bold.woff";

[@bs.module]
external playfairDisplayBold: string =
  "../static/fonts/PlayfairDisplay-Bold.woff";

fontFace(
  ~fontFamily="Karmilla",
  ~src=[url(karmillaRegular)],
  ~fontStyle=`normal,
  ~fontWeight=`num(400),
  (),
);

fontFace(
  ~fontFamily="Karmilla",
  ~src=[url(karmillaBold)],
  ~fontStyle=`normal,
  ~fontWeight=`num(700),
  (),
);

fontFace(
  ~fontFamily="PlayfairDisplay",
  ~src=[url(playfairDisplayBold)],
  ~fontStyle=`normal,
  ~fontWeight=`num(700),
  (),
);

// Eric Meyer's reset CSS

global(
  "html, body, div, span, applet, object, iframe, h1, h2, h3, h4, h5, h6, p, blockquote, pre, a, abbr, acronym, address, big, cite, code, del, dfn, em, img, ins, kbd, q, s, samp, small, strike, strong, sub, sup, tt, var, b, u, i, center, dl, dt, dd, ol, ul, li, fieldset, form, label, legend, table, caption, tbody, tfoot, thead, tr, th, td, article, aside, canvas, details, embed, figure, figcaption, footer, header, hgroup, menu, nav, output, ruby, section, summary, time, mark, audio, video",
  [
    borderWidth(0->px),
    fontSize(100.->pct),
    margin(0->px),
    padding(0->px),
    verticalAlign(`baseline),
    unsafe("font", "inherit"),
  ],
);

global("blockquote, q", [unsafe("quotes", "none")]);

global(
  "blockquote:before, blockquote:after, q:before, q:after",
  [unsafe("content", "''"), unsafe("content", "none")],
);

global("ol, ul", [listStyleType(`none)]);
global("table", [borderCollapse(`collapse), borderSpacing(0->px)]);

// sanitize and default CSS

global(
  "html",
  [
    boxSizing(`borderBox),
    cursor(`default),
    unsafe("textSizeAdjust", "100%"),
    unsafe("tabSize", "2"),
  ],
);

global(
  "body",
  [
    backgroundColor(Theme.whiteColor),
    display(`flex),
    flexDirection(`column),
    fontFamily(Theme.baseFontFamily),
    letterSpacing((-0.02)->em),
    lineHeight(`abs(1.65)),
    unsafe("WebkitFontSmoothing", "antialiased"),
    unsafe("MozOsxFontSmoothing", "grayscale"),
  ],
);

global(
  "*, ::before, ::after",
  [backgroundRepeat(`noRepeat), boxSizing(`inherit_)],
);

global(
  "::before, ::after",
  [textDecoration(`inherit_), verticalAlign(`inherit_)],
);

global(
  "::selection",
  [
    backgroundColor(hex("b3d4fc")),
    color(black),
    unsafe("textShadow", "none"),
  ],
);

global(
  "::-webkit-input-placeholder",
  [color(`currentColor), opacity(0.54)],
);

global(
  "#root",
  [
    display(`flex),
    flexDirection(`column),
    flexGrow(1.),
    overflowX(`hidden),
    width(100.->pct),
  ],
);

global("code, kbd, pre, samp", [fontFamily(Theme.monospaceFontFamily)]);

global(
  "img, canvas, iframe, video, svg, select, textarea",
  [maxWidth(100.->pct)],
);

global(
  "audio, canvas, iframe, img, svg, video",
  [unsafe("touchAction", "manipulation")],
);

global("textarea", [unsafe("resize", "vertical")]);
global("svg:not([fill])", [SVG.fill(`currentColor)]);
global("[aria-busy=\"true\"]", [cursor(`progress)]);
global("[aria-controls]", [cursor(`pointer)]);
global("[aria-disabled=\"true\"], [disabled]", [cursor(`notAllowed)]);

global(
  "[aria-hidden=\"false\"][hidden]:not(:focus)",
  [
    display(`inherit_),
    position(`absolute),
    unsafe("clip", "rect(0,0,0,0)"),
  ],
);
