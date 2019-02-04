let component = ReasonReact.statelessComponent("Component1");

let make = _children => {
  ...component,
  render: _self => ReasonReact.string("Hello world"),
};
