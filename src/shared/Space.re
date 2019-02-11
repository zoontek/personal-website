let component = React.statelessComponent("Space");

let make = (~h=?, ~w=?, _children) => {
  ...component,
  render: _self => {
    let height =
      switch (h) {
      | Some(value) => Css.(height(value->px))
      | None => Css.height(`auto)
      };
    let width =
      switch (w) {
      | Some(value) => Css.(width(value->px))
      | None => Css.width(`auto)
      };

    <div className={Css.style([height, width])} />;
  },
};
