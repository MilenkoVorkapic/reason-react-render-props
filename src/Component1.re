/* This is the basic component. */
let component = ReasonReact.statelessComponent("Page");


/* `make` is the function that mandatorily takes `children` (if you want to use
   `JSX). `message` is a named argument, which simulates ReactJS props. Usage:

   `<Page message="hello" />`

   Which desugars to

   `ReasonReact.element(Page.make(~message="hello", [||]))` */
let make = (~props, ~message, _children) => {
  ...component,
  render: self =>
    <button onClick=(props)>
      (ReasonReact.string(message))
    </button>,
};
