let component = ReasonReact.statelessComponent("App");

let make = _children => {
  ...component,
  render: _self => ReasonReact.string({js|Hi, I'm Mathieu Acthernoene !|js}),
};
