[@bs.module] external illustration: string = "./static/media/illustration.svg";

type state = {email: string};

type action =
  | SwapEmail;

let component = React.reducerComponent("App");

module Styles = {
  open Css;

  let hero = style([backgroundColor(Theme.primaryColor)]);

  let header =
    style([
      alignItems(`center),
      display(`flex),
      justifyContent(`spaceBetween),
      paddingTop(32->px),
      paddingBottom(32->px),
      paddingLeft(4->px),
      paddingRight(4->px),
      media("(min-width: 768px)", [flexDirection(`row)]),
    ]);

  let heroContent =
    style([
      borderRadius(2->px),
      flexWrap(`wrap),
      media("(min-width: 992px)", [flexDirection(`row)]),
    ]);

  let introContainer =
    style([
      flex(4),
      justifyContent(`center),
      paddingTop((100.0 /. (1440.0 /. 144.0))->vw),
      paddingBottom((100.0 /. (1440.0 /. 192.0))->vw),
      media(
        "(min-width: 1440px)",
        [paddingTop(144->px), paddingBottom(192->px)],
      ),
    ]);

  let text =
    style([
      fontSize(Theme.baseFontSize),
      color(Theme.textColor),
      letterSpacing((-0.02)->em),
    ]);

  let illustrationContainer = style([flex(6)]);

  let illustration =
    style([
      marginBottom((-2.5)->vw),
      media(
        "(min-width: 992px)",
        [
          position(`absolute),
          marginBottom(0->px),
          right((-16)->px),
          bottom((-1.4)->vw),
        ],
      ),
      media("(min-width: 1440px)", [bottom((-22)->px)]),
    ]);

  let menuNav = style([flex(1), alignItems(`flexEnd)]);

  let menuList =
    style([
      justifyContent(`flexEnd),
      flex(1),
      flexDirection(`row),
      flexWrap(`wrap),
      media(
        "(max-width: 768px)",
        [marginTop(8->px), justifyContent(`center)],
      ),
    ]);

  let menuLink =
    style([
      color(Theme.textColor),
      opacity(0.9),
      fontSize(17->px),
      marginLeft(32->px),
      position(`relative),
      textDecoration(`none),
      textTransform(`uppercase),
      zIndex(1),
      media(
        "(max-width: 768px)",
        [marginLeft(16->px), marginRight(16->px)],
      ),
      before([
        unsafe("content", "''"),
        position(`absolute),
        borderRadius(2->px),
        top(0->px),
        bottom(4->px),
        left((-4)->px),
        right((-4)->px),
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
    <View className=Styles.hero>
      <View
        className=Css.(
          style([
            maxWidth(1440->px),
            alignSelf(`center),
            paddingLeft(40->px),
            paddingRight(40->px),
          ])
        )>
        <View role=Banner className=Styles.header>
          <h1 className=Styles.websiteTitle>
            {React.string(Content.websiteTitle)}
          </h1>
          <View role=Navigation className=Styles.menuNav>
            <View role=List className=Styles.menuList>
              <li>
                <Link
                  href={"mailto:" ++ self.state.email}
                  className=Styles.menuLink>
                  {React.string("contact")}
                </Link>
              </li>
              <li>
                <Link href=Content.twitterUrl className=Styles.menuLink>
                  {React.string("twitter")}
                </Link>
              </li>
              <li>
                <Link href=Content.githubUrl className=Styles.menuLink>
                  {React.string("github")}
                </Link>
              </li>
            </View>
          </View>
        </View>
        <View className=Styles.heroContent>
          <View className=Styles.introContainer>
            <Title level=H1> {React.string({js|Hello !|js})} </Title>
            <Space scale=3 />
            <p className=Styles.text>
              {React.string(
                 "I am Mathieu Acthernoene (aka @zoontek), a front-end developer living in Paris, France. I currently work at BeOp, where we build a third-party solution for editors on the web, enabling them to create interactive.",
               )}
            </p>
          </View>
          <Space direction=Horizontal scale=8 />
          <View className=Styles.illustrationContainer>
            <img className=Styles.illustration src=illustration />
          </View>
        </View>
      </View>
    </View>,
  // <View className=Css.({style([padding(64->px)])})>
  //   <Title level=H2> {React.string("Things I work with")} </Title>
  //   <View role=List className=Styles.text>
  //     <li> {React.string("- React Native")} </li>
  //     <li> {React.string("- React")} </li>
  //     <li> {React.string("- gRPC")} </li>
  //     <li> {React.string("- Jest")} </li>
  //     <li> {React.string("- Sketch")} </li>
  //     <li> {React.string("- JavaScript")} </li>
  //     <li> {React.string("- TypeScript")} </li>
  //     <li> {React.string("- Flow")} </li>
  //   </View>
  // </View>
  // <View className=Css.({style([padding(64->px)])})>
  //   <Title level=H2> {React.string("Things I work on")} </Title>
  //   <View role=List className=Styles.text>
  //     <li> {React.string("- Scaleway Control Panel")} </li>
  //     <li> {React.string("- Wulo mobile app")} </li>
  //     <li> {React.string("- Colisweb mobile app")} </li>
  //     <li> {React.string("- Onemore agency")} </li>
  //   </View>
  // </View>
  // <View className=Css.({style([padding(64->px)])})>
  //   <Title level=H2> {React.string("Talks I gave")} </Title>
  //   <View role=List className=Styles.text>
  //     <li>
  //       {React.string(
  //          "- Modern services communication with gRPC (ParisJS)",
  //        )}
  //     </li>
  //     <li>
  //       {React.string(
  //          "- Enhance your JavaScript with Flow (Algolia TechLunch, Take Off Talks)",
  //        )}
  //     </li>
  //     <li>
  //       {React.string("- Your first React Native app (ChtiJS #16)")}
  //     </li>
  //     <li>
  //       {React.string("- Handle your app state with Redux (ChtiJS #15)")}
  //     </li>
  //     <li> {React.string("- Electron presentation (ChtiJS #14)")} </li>
  //     <li>
  //       {React.string(
  //          "- React Motion: animations done right (WelshDesign #7)",
  //        )}
  //     </li>
  //   </View>
  // </View>
  // <View className=Css.({style([padding(64->px)])})>
  //   <Title level=H2> {React.string("Activities I enjoy")} </Title>
  //   <View role=List className=Styles.text>
  //     <li> {React.string("- Commuter bike")} </li>
  //     <li> {React.string("- Swimming")} </li>
  //     <li> {React.string("- Hiking")} </li>
  //     <li> {React.string("- Podcasting")} </li>
  //     <li> {React.string("- Climbing")} </li>
  //   </View>
  // </View>
  // <View role=ContentInfo />
};
