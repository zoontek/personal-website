[@bs.module] external illustration: string = "./static/media/illustration.svg";

type state = {email: string};

type action =
  | SwapEmail;

let component = React.reducerComponent("App");

module Styles = {
  open Css;

  let hero = style([backgroundColor(Theme.primaryColor), margin(16->px)]);

  let osef =
    style([
      // minHeight(560->px), define max height
      flexDirection(`row),
      height(32.->vh), // dont do that
      borderRadius(2->px),
    ]);

  let osef2 =
    style([
      justifyContent(`center), // delete this line
      flex(1), // 4 and 6
      paddingLeft(56->px),
      paddingRight(56->px),
      paddingTop(32->px),
      paddingBottom(48->px),
    ]);

  let text = style([color(Theme.textColor), fontSize(Theme.baseFontSize)]);

  let image =
    style([
      maxWidth(100.->pct),
      position(`absolute),
      bottom(px(-20)),
      // left(64->px),
      right(32->px),
    ]);

  let header =
    style([
      alignItems(`center),
      display(`flex),
      flexDirection(`row),
      justifyContent(`spaceBetween),
      paddingTop(30->px),
      paddingLeft(40->px),
      paddingRight(40->px),
    ]);

  let menu =
    style([listStyleType(`none), display(`flex), flexDirection(`row)]);

  let menuLink =
    style([
      color(Theme.textColor),
      fontSize(17->px),
      paddingLeft(8->px),
      paddingRight(8->px),
      paddingTop(4->px),
      position(`relative),
      textDecoration(`none),
      zIndex(1),
      before([
        unsafe("content", "''"),
        position(`absolute),
        borderRadius(2->px),
        top(0->px),
        bottom(4->px),
        left(4->px),
        right(4->px),
        verticalAlign(`baseline),
        zIndex(-1),
        backgroundColor(hex("f2cc6c")),
        transform(scaleY(0.)),
        transformOrigin(50.->pct, 100.->pct),
        transitionProperty("transform"),
        transitionDuration(150),
        transitionTimingFunction(`ease),
      ]),
      hover([before([transform(scaleY(0.4))])]),
    ]);

  let websiteTitle =
    style([color(Theme.titleColor), fontSize(17->px), fontWeight(`bold)]);
};

let make = _children => {
  ...component,
  initialState: () => {email: ""},
  reducer: (action, _state) =>
    switch (action) {
    | SwapEmail => React.Update({email: Content.emailAddress})
    },
  didMount: self => {
    self.send(SwapEmail);
  },
  render: self =>
    <View>
      <View className=Styles.hero>
        <View role=Banner className=Styles.header>
          <h1 className=Styles.websiteTitle>
            {React.string(Content.websiteTitle)}
          </h1>
          <nav>
            <ul className=Styles.menu>
              <li>
                <Link
                  href={"mailto:" ++ self.state.email}
                  className=Styles.menuLink>
                  {React.string("CONTACT")}
                </Link>
              </li>
              <Space direction=Horizontal scale=2 />
              <li>
                <Link href=Content.twitterUrl className=Styles.menuLink>
                  {React.string("TWITTER")}
                </Link>
              </li>
              <Space direction=Horizontal scale=2 />
              <li>
                <Link href=Content.githubUrl className=Styles.menuLink>
                  {React.string("GITHUB")}
                </Link>
              </li>
            </ul>
          </nav>
        </View>
        <View className=Styles.osef>
          <View className=Styles.osef2>
            <Title level=H1> {React.string("Hello !")} </Title>
            <p className=Styles.text>
              {React.string(
                 "I am Mathieu Acthernoene (aka @zoontek), a front-end developer living in Paris, France. I currently work at BeOp, where we build a third-party solution for editors on the web, enabling them to create interactive content without any technical knowledge and to monetize their pages.",
               )}
            </p>
          </View>
          <View className=Styles.osef2>
            <img className=Styles.image src=illustration />
          </View>
        </View>
      </View>
      <View className=Css.({style([padding(64->px)])})>
        <Title level=H2> {React.string("Things I work with")} </Title>
        <View role=List className=Styles.text>
          <li> {React.string("- React Native")} </li>
          <li> {React.string("- React")} </li>
          <li> {React.string("- gRPC")} </li>
          <li> {React.string("- Jest")} </li>
          <li> {React.string("- Sketch")} </li>
          <li> {React.string("- JavaScript")} </li>
          <li> {React.string("- TypeScript")} </li>
          <li> {React.string("- Flow")} </li>
        </View>
      </View>
      <View className=Css.({style([padding(64->px)])})>
        <Title level=H2> {React.string("Things I work on")} </Title>
        <View role=List className=Styles.text>
          <li> {React.string("- Scaleway Control Panel")} </li>
          <li> {React.string("- Wulo mobile app")} </li>
          <li> {React.string("- Colisweb mobile app")} </li>
          <li> {React.string("- Onemore agency")} </li>
        </View>
      </View>
      <View className=Css.({style([padding(64->px)])})>
        <Title level=H2> {React.string("Talks I gave")} </Title>
        <View role=List className=Styles.text>
          <li>
            {React.string(
               "- Modern services communication with gRPC (ParisJS)",
             )}
          </li>
          <li>
            {React.string(
               "- Enhance your JavaScript with Flow (Algolia TechLunch, Take Off Talks)",
             )}
          </li>
          <li>
            {React.string("- Your first React Native app (ChtiJS #16)")}
          </li>
          <li>
            {React.string("- Handle your app state with Redux (ChtiJS #15)")}
          </li>
          <li> {React.string("- Electron presentation (ChtiJS #14)")} </li>
          <li>
            {React.string(
               "- React Motion: animations done right (WelshDesign #7)",
             )}
          </li>
        </View>
      </View>
      <View className=Css.({style([padding(64->px)])})>
        <Title level=H2> {React.string("Activities I enjoy")} </Title>
        <View role=List className=Styles.text>
          <li> {React.string("- Commuter bike")} </li>
          <li> {React.string("- Swimming")} </li>
          <li> {React.string("- Hiking")} </li>
          <li> {React.string("- Podcasting")} </li>
          <li> {React.string("- Climbing")} </li>
        </View>
      </View>
      <View role=ContentInfo />
    </View>,
};
