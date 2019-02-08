let component = React.statelessComponent("Space");

let make = (~height=0, ~width=0, _children) => {
  ...component,
  render: _self => {
    <div
      className={Css.style([
        Css.height(
          switch (height) {
          | 0 => `auto
          | _ => Css.px(height)
          },
        ),
        Css.width(
          switch (width) {
          | 0 => `auto
          | _ => Css.px(width)
          },
        ),
      ])}
    />;
  },
};
