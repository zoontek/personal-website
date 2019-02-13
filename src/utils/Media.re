let whenSm = rules => Css.media("(min-width: 576px)", rules);
let whenMd = rules => Css.media("(min-width: 768px)", rules);
let whenLg = rules => Css.media("(min-width: 992px)", rules);
let whenXl = rules => Css.media("(min-width: 1200px)", rules);

let whenHover = rules => Css.(media("(hover: hover)", [hover(rules)]));
