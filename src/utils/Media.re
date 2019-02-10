let isSm = rules => Css.media("(min-width: 576px)", rules);
let isMd = rules => Css.media("(min-width: 768px)", rules);
let isLg = rules => Css.media("(min-width: 992px)", rules);
let isXl = rules => Css.media("(min-width: 1200px)", rules);

let isHover = rules => Css.(media("(hover: hover)", [hover(rules)]));
