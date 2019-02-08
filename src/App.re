[@bs.module] external illustration: string = "./static/media/illustration.svg";

type state = {email: string};

type action =
  | SwapEmail;

let component = React.reducerComponent("App");

module Styles = {
  open Css;

  let hero =
    style([backgroundColor(Theme.primaryColor), borderRadius(2->px)]);

  let heroContent =
    style([
      maxWidth(1440->px),
      alignSelf(`center),
      paddingLeft(24->px),
      paddingRight(24->px),
      media(
        Theme.smBreakPoint,
        [paddingLeft(40->px), paddingRight(40->px)],
      ),
    ]);

  let header =
    style([
      display(`flex),
      paddingTop(24->px),
      paddingBottom(24->px),
      media(
        Theme.smBreakPoint,
        [
          flexDirection(`row),
          justifyContent(`spaceBetween),
          paddingTop(32->px),
          paddingBottom(32->px),
        ],
      ),
    ]);

  let websiteTitle =
    style([
      color(Theme.titleColor),
      fontSize(Theme.baseFontSize),
      fontWeight(`bold),
    ]);

  let menuNav = style([flexShrink(1)]);

  let menuList =
    style([
      alignItems(`center),
      flex(1),
      flexDirection(`row),
      flexWrap(`wrap),
      marginTop(12->px),
      media(
        Theme.smBreakPoint,
        [marginTop(0->px), justifyContent(`flexEnd)],
      ),
    ]);

  let menuLink =
    style([
      color(Theme.textColor),
      letterSpacing(`normal),
      opacity(0.9),
      marginLeft(0->px),
      marginRight(24->px),
      position(`relative),
      textDecoration(`none),
      textTransform(`uppercase),
      zIndex(1),
      media(Theme.smBreakPoint, [marginLeft(32->px), marginRight(0->px)]),
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
      media(
        "(hover: hover)",
        [hover([before([transform(scaleY(0.4))])])],
      ),
    ]);

  let introAndIllustration =
    style([media(Theme.smBreakPoint, [flexDirection(`row)])]);

  let introContent =
    style([
      flex(4),
      justifyContent(`center),
      paddingTop((100.0 /. (1440.0 /. 144.0))->vw),
      paddingBottom((100.0 /. (1440.0 /. 192.0))->vw),
      media(
        Theme.xlBreakPoint,
        [paddingTop(144->px), paddingBottom(192->px)],
      ),
    ]);

  let text = style([fontSize(Theme.baseFontSize), color(Theme.textColor)]);

  let illustrationContainer =
    style([
      flex(6),
      marginLeft((-72)->px),
      marginRight((-72)->px),
      media(
        Theme.smBreakPoint,
        [marginLeft((-0)->px), marginRight((-0)->px)],
      ),
    ]);

  let illustration =
    style([
      marginBottom((-2.5)->vw),
      media(
        Theme.smBreakPoint,
        [
          position(`absolute),
          marginBottom(0->px),
          right((-24)->px),
          bottom((-1.4)->vw),
        ],
      ),
      media(Theme.xlBreakPoint, [bottom((-22)->px)]),
    ]);

  let contentBlock =
    style([
      maxWidth(1440->px),
      width(100.->pct),
      alignSelf(`center),
      paddingLeft(24->px),
      paddingRight(24->px),
      media(
        Theme.smBreakPoint,
        [paddingLeft(40->px), paddingRight(40->px)],
      ),
    ]);
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
    <>
      <View className=Styles.hero>
        <View className=Styles.heroContent>
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
                  <Link href=Content.githubUrl className=Styles.menuLink>
                    {React.string("github")}
                  </Link>
                </li>
                <li>
                  <Link href=Content.twitterUrl className=Styles.menuLink>
                    {React.string("twitter")}
                  </Link>
                </li>
              </View>
            </View>
          </View>
          <View className=Styles.introAndIllustration>
            <View className=Styles.introContent>
              <Title level=H1> {React.string({js|Hello !|js})} </Title>
              <Space height=24 />
              <p className=Styles.text>
                {React.string(
                   "I am Mathieu Acthernoene (aka @zoontek), a front-end developer living in Paris, France. I currently work at BeOp, where we build a third-party solution for editors on the web, enabling them to create interactive.",
                 )}
              </p>
            </View>
            <Space height=32 />
            <View className=Styles.illustrationContainer>
              <img className=Styles.illustration src=illustration />
            </View>
          </View>
        </View>
      </View>
      <Space height=128 />
      <View className=Styles.contentBlock>
        <Title level=H2> {React.string("Things I work with")} </Title>
        <Space height=24 />
        <View role=List className=Styles.text>
          <li> {React.string("React Native")} </li>
          <li> {React.string("React")} </li>
          <li> {React.string("gRPC")} </li>
          <li> {React.string("Jest")} </li>
          <li> {React.string("Sketch")} </li>
          <li> {React.string("JavaScript")} </li>
          <li> {React.string("TypeScript")} </li>
          <li> {React.string("Flow")} </li>
        </View>
      </View>
      <Space height=72 />
      <View className=Styles.contentBlock>
        <Title level=H2> {React.string("Things I work on")} </Title>
        <Space height=24 />
        <View role=List className=Styles.text>
          <li> {React.string("Scaleway Control Panel")} </li>
          <li> {React.string("Wulo mobile app")} </li>
          <li> {React.string("Colisweb mobile app")} </li>
          <li> {React.string("Onemore agency")} </li>
        </View>
      </View>
      <Space height=72 />
      <View className=Styles.contentBlock>
        <Title level=H2> {React.string("Talks I gave")} </Title>
        <Space height=24 />
        <View role=List className=Styles.text>
          <li>
            {React.string("Modern services communication with gRPC (ParisJS)")}
          </li>
          <li>
            {React.string(
               "Enhance your JavaScript with Flow (Algolia TechLunch, Take Off Talks)",
             )}
          </li>
          <li>
            {React.string("Your first React Native app (ChtiJS #16)")}
          </li>
          <li>
            {React.string("Handle your app state with Redux (ChtiJS #15)")}
          </li>
          <li> {React.string("Electron presentation (ChtiJS #14)")} </li>
          <li>
            {React.string(
               "React Motion: animations done right (WelshDesign #7)",
             )}
          </li>
        </View>
      </View>
      <Space height=72 />
      <View className=Styles.contentBlock>
        <Title level=H2> {React.string("Activities I enjoy")} </Title>
        <Space height=24 />
        <View role=List className=Styles.text>
          <li> {React.string("Commuter bike")} </li>
          <li> {React.string("Swimming")} </li>
          <li> {React.string("Hiking")} </li>
          <li> {React.string("Podcasting")} </li>
          <li> {React.string("Climbing")} </li>
        </View>
      </View>
      <Space height=128 />
      <View role=ContentInfo />
    </>,
};
