/* State declaration */
type state = {
  count: int,
  show: bool,
  search: string,
};

/* Action declaration */
type action =
  | Increment
  | Decrement
  | Toggle
  | Search(string);

/* Component template declaration.
   Needs to be **after** state and action declarations! */
let component = ReasonReact.reducerComponent("Example");

/* greeting and children are props. `children` isn't used, therefore ignored.
   We ignore it by prepending it with an underscore */
  let s = ReasonReact.string;

  let make = (_children) => {
  let click= (_event, self) => self.ReasonReact.send(Toggle);
  {
  /* spread the other defajult fields of component here and override a few */
  ...component,
  initialState: () => {count: 0, show: false, search: "Milenkoo"},
  /* State transitions */
  reducer: (action, state) =>
    switch (action) {
    | Increment => ReasonReact.Update({...state, count: state.count + 1})
    | Decrement => ReasonReact.Update({...state, count: state.count - 1})
    | Toggle => ReasonReact.Update({...state, show: ! state.show})
    | Search(name) => ReasonReact.Update({...state, search: name})
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

      <Component1 props={self.handle(click)} message=(printedState) ></Component1>

      <input value=self.state.search onChange={(event) => self.send(Search(ReactDOMRe.domElementToObj(ReactEventRe.Form.target(event))##value))}/>

      <ChildrenAsProps githubName={self.state.search}>
        ...{(img, err) => <div>
           (err !== "" ? <p>(s(err))</p> :<img src=img />)
        </div>}
      </ChildrenAsProps>

      <RenderProps render={(number) => <h1>(s(string_of_int(number)))</h1>} />
    </div>;
  },
}
};
