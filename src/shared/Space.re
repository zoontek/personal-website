type direction =
  | Horizontal
  | Vertical;

let component = React.statelessComponent("Space");

let make = (~scale, ~direction=Vertical, _children) => {
  ...component,
  render: _self => {
    let pxValue = Css.px(scale * 8);

    switch (direction) {
    | Horizontal =>
      <div className=Css.(style([height(`auto), width(pxValue)])) />
    | Vertical =>
      <div className=Css.(style([height(pxValue), width(`auto)])) />
    };
  },
};
