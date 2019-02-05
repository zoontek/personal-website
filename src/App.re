let component = ReasonReact.statelessComponent("App");

module Styles = {
  open Css;

  let title = style([fontWeight(`normal), fontSize(48->px)]);
  let name = style([fontWeight(`bold)]);
};

let make = _children => {
  ...component,
  render: _self =>
    <h1 className=Styles.title>
      {ReasonReact.string("Hi, I'm ")}
      <span className=Styles.name>
        {ReasonReact.string("Mathieu Acthernoene")}
      </span>
    </h1>,
};
