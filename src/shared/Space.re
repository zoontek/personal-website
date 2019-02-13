let component = React.statelessComponent("Space");

let make = (~h=?, ~w=?, _children) => {
  ...component,
  render: _self => {
    Css.(
      {
        let height =
          switch (h) {
          | Some(value) => height(value->px)
          | None => height(`auto)
          };
        let width =
          switch (w) {
          | Some(value) => width(value->px)
          | None => width(`auto)
          };

        <div className={style([height, width])} />;
      }
    );
  },
};
