type viewRole =
  | Article
  | Banner
  | Complementary
  | ContentInfo
  | Form
  | List
  | ListItem
  | Main
  | Navigation
  | Region;

let component = React.statelessComponent("View");

module Styles = {
  open Css;

  let base =
    style([
      alignItems(`stretch),
      borderWidth(0->px),
      borderStyle(`solid),
      boxSizing(`borderBox),
      display(`flex),
      flexBasis(`auto),
      flexDirection(`column),
      flexShrink(0),
      margin(0->px),
      padding(0->px),
      position(`relative),
      // fix flexbox bugs
      minHeight(0->px),
      minWidth(0->px),
    ]);
};

let make = (~role=?, ~className=?, children) => {
  ...component,
  render: _self => {
    let className =
      switch (className) {
      | Some(className) => Css.merge([Styles.base, className])
      | _ => Styles.base
      };

    switch (role) {
    | Some(Article) => <article className> ...children </article>
    | Some(Banner) => <header className> ...children </header>
    | Some(Complementary) => <aside className> ...children </aside>
    | Some(ContentInfo) => <footer className> ...children </footer>
    | Some(Form) => <form className> ...children </form>
    | Some(List) => <ul className> ...children </ul>
    | Some(ListItem) => <li className> ...children </li>
    | Some(Main) => <main className> ...children </main>
    | Some(Navigation) => <nav className> ...children </nav>
    | Some(Region) => <section className> ...children </section>
    | None => <div className> ...children </div>
    };
  },
};
