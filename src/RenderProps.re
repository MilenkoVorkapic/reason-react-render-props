let component = ReasonReact.statelessComponent("RenderProps")

let make = (~render, _children) => {
  ...component,
  render: _self => render(1)
}