/* State declaration */
type state = {
  count: int,
  show: bool,
};

/* Action declaration */
type action =
  | Increment
  | Decrement
  | Toggle;

/* Component template declaration.
   Needs to be **after** state and action declarations! */
let component = ReasonReact.reducerComponent("Example");

/* greeting and children are props. `children` isn't used, therefore ignored.
   We ignore it by prepending it with an underscore */
  let s = ReasonReact.string;

  let make = (_children) => {
  let click= (_event, self) => self.ReasonReact.send(Toggle);
  {
  /* spread the other default fields of component here and override a few */
  ...component,
  initialState: () => {count: 0, show: false},
  /* State transitions */
  reducer: (action, state) =>
    switch (action) {
    | Increment => ReasonReact.Update({...state, count: state.count + 1})
    | Decrement => ReasonReact.Update({...state, count: state.count - 1})
    | Toggle => ReasonReact.Update({...state, show: ! state.show})
    },

  render: self => {
    let message = "Counter " ++ string_of_int(self.state.count);
    let printedState = message ++ " State is now shown";
    <div>
      <button onClick=(_event => self.send(Increment))> (s("Increment")) </button>
      <button onClick=(_event => self.send(Decrement))> (s("Decrement")) </button>
      <div>
        <button onClick={self.handle(click)}>(s("Toggle the state")) </button>
      </div>
      (self.state.show ? <h1>(s(printedState))</h1> : ReasonReact.null)

      <Component1 props={self.handle(click)} message=(printedState) />

      <ChildrenAsProps>
        ...{(text) => <h1> (s(text))</h1>}
      </ChildrenAsProps>

      <RenderProps render={(number) => <h1>(s(string_of_int(number)))</h1>} />
    </div>;
  },
}
};
