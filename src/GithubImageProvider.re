type state = {
  avatar_url: string,
  error: string
};

/* Action declaration */
type action =
  | SetData(string)
  | SetError;

let component = ReasonReact.reducerComponent("GithubImageProvider");

let make = (~githubName, children) => {
  ...component,
  initialState: () => {avatar_url: "", error: ""},
  reducer: (action, state) =>
    switch (action) {
    | SetData(name) => ReasonReact.Update({avatar_url: name, error: ""})
    | SetError => ReasonReact.Update({avatar_url: "", error: "Error"})
    },
  didMount: self => {
    Js.Promise.(
      Axios.get("https://api.github.com/users/" ++ githubName)
        |> then_((response) => resolve(self.send(SetData(response##data##avatar_url))))
        |> catch((_error) => resolve(self.send(SetError)))
        |> ignore
    );
  },
  willReceiveProps: self => {
    Js.Promise.(
      Axios.get("https://api.github.com/users/" ++ githubName)
        |> then_((response) => resolve(self.send(SetData(response##data##avatar_url))))
        |> catch((_error) => resolve(self.send(SetError)))
        |> ignore
    );
    self.state
  },
  render: self =>
    children(self.state.avatar_url, self.state.error)
}