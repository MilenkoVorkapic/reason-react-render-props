let component = ReasonReact.statelessComponent("RenderProps")

let make = (~render, _children) => {
  ...component,
  render: self => render(1)
}