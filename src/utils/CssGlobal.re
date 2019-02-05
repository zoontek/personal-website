[@bs.module]
external quasimodaRegular: string = "../static/fonts/Quasimoda-Regular.woff";
[@bs.module]
external quasimodaBold: string = "../static/fonts/Quasimoda-Bold.woff";

let sansSerifFonts = [|
  "Quasimoda",
  "-apple-system",
  "BlinkMacSystemFont",
  "\"Segoe UI\"",
  "Helvetica",
  "Arial",
  "sans-serif",
|];

let monospaceFonts = [|
  "SFMono-Regular",
  "Consolas",
  "\"Liberation Mono\"",
  "Menlo",
  "Courier",
  "monospace",
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
  global(
    "*, ::before, ::after",
    [backgroundRepeat(`noRepeat), boxSizing(`inherit_)],
  ),
  global(
    "::before, ::after",
    [textDecoration(`inherit_), verticalAlign(`inherit_)],
  ),
  global(
    "::selection",
    [
      backgroundColor(hex("b3d4fc")),
      color(hex("000")),
      unsafe("textShadow", "none"),
    ],
  ),
  global(
    "::-webkit-input-placeholder",
    [color(`currentColor), opacity(0.54)],
  ),
  global(
    "html",
    [
      boxSizing(`borderBox),
      cursor(`default),
      unsafe("tabSize", "2"),
      unsafe("textSizeAdjust", "100%"),
    ],
  ),
  global(
    "body",
    [
      fontFamily(Js.Array.join(sansSerifFonts)),
      padding(0->px),
      unsafe("WebkitFontSmoothing", "antialiased"),
      unsafe("MozOsxFontSmoothing", "grayscale"),
    ],
  ),
  global(
    "code, kbd, pre, samp",
    [
      padding(0->px),
      fontFamily(Js.Array.join(monospaceFonts)),
      fontSize(1.->em),
    ],
  ),
  global(
    "audio, canvas, iframe, img, svg, video",
    [unsafe("touchAction", "manipulation")],
  ),
  global(
    "dialog",
    [
      backgroundColor(hex("fff")),
      borderStyle(`solid),
      color(hex("000")),
      display(`block),
      left(0->px),
      margin(`auto),
      padding(1.->em),
      position(`absolute),
      right(0->px),
      unsafe("height", "fit-content"),
      unsafe("width", "fit-content"),
    ],
  ),
  global("dialog:not([open])", [display(`none)]),
  global("nav ol, nav ul", [listStyleType(`none)]),
  global("table", [borderCollapse(`collapse)]),
  global("textarea", [unsafe("resize", "vertical")]),
  global("svg:not([fill])", [SVG.fill(`currentColor)]),
  global("[aria-busy=\"true\"]", [cursor(`progress)]),
  global("[aria-controls]", [cursor(`pointer)]),
  global("[aria-disabled=\"true\"], [disabled]", [cursor(`notAllowed)]),
  global(
    "[aria-hidden=\"false\"][hidden]:not(:focus)",
    [
      display(`inherit_),
      position(`absolute),
      unsafe("clip", "rect(0, 0, 0, 0)"),
    ],
  ),
);
