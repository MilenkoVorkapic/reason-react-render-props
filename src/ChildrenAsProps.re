let component = ReasonReact.statelessComponent("ChildrenProps");

let make = (~children) => {
  ...component,
  render: _self =>
    children("Hello")
}