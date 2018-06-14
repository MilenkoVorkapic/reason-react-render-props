/* State declaration */
type state = {
  search: string,
};

/* Action declaration */
type action =
  | Search(string);

/* Component template declaration.
   Needs to be **after** state and action declarations! */
let component = ReasonReact.reducerComponent("App");

  let s = ReasonReact.string;

  let make = (_children) => {
  {
  /* spread the other defajult fields of component here and override a few */
  ...component,
  initialState: () => {search: "Milenkoo"},
  /* State transitions */
  reducer: (action, _state) =>
    switch (action) {
    | Search(name) => ReasonReact.Update({search: name})
  },

  render: self => {
    <div>
      <input value=self.state.search onChange={(event) => self.send(Search(ReactDOMRe.domElementToObj(ReactEventRe.Form.target(event))##value))}/>
      <GithubImageProvider githubName={self.state.search}>
        ...{(img, err) =>
          <div>
           (err !== "" ? <p>(s(err))</p> :<img src=img />)
        </div>
      }
      </GithubImageProvider>

      <RenderProps render={(number) => <h1>(s(string_of_int(number)))</h1>} />
    </div>;
  },
}
};
