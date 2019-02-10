open Belt;

[@bs.module] external illustration: string = "./static/media/illustration.svg";
[@bs.module] external scaleway: string = "./static/media/scaleway.svg";

type state = {email: string};

type action =
  | SwapEmail;

let component = React.reducerComponent("App");

module Styles = {
  open Css;

  let flexed = style([display(`flex)]);

  let container =
    style([alignSelf(`center), maxWidth(1200->px), width(100.->pct)]);

  let block =
    style([
      paddingLeft(16->px),
      paddingRight(16->px),
      Media.isMd([paddingLeft(32->px), paddingRight(32->px)]),
    ]);

  let text = style([fontSize(Theme.baseFontSize), color(Theme.textColor)]);

  let title =
    style([
      color(Theme.titleColor),
      display(`flex),
      fontFamily("PlayfairDisplay"),
      fontWeight(`num(700)),
      lineHeight(`abs(1.2)),
    ]);

  let hero =
    style([
      backgroundColor(Theme.primaryColor),
      margin(16->px),
      borderRadius(2->px),
    ]);

  let header =
    style([
      paddingLeft(4->px),
      paddingRight(4->px),
      paddingTop(24->px),
      paddingBottom(24->px),
      Media.isMd([
        alignItems(`center),
        flexDirection(`row),
        justifyContent(`spaceBetween),
      ]),
    ]);

  let siteTitle =
    style([
      color(Theme.titleColor),
      display(`flex),
      fontSize(Theme.baseFontSize),
      fontWeight(`bold),
      marginBottom(4->px),
      Media.isMd([marginBottom(0->px)]),
    ]);

  let menuNav = style([flexShrink(1)]);

  let menuList =
    style([
      flexDirection(`row),
      flexWrap(`wrap),
      Media.isMd([justifyContent(`flexEnd)]),
    ]);

  let menuLink =
    style([
      color(Theme.textColor),
      letterSpacing(`normal),
      opacity(0.9),
      marginRight(16->px),
      position(`relative),
      textDecoration(`none),
      textTransform(`uppercase),
      zIndex(1),
      before([
        unsafe("content", "''"),
        position(`absolute),
        borderRadius(2->px),
        top(0->px),
        bottom(0.25->em),
        left((-0.125)->em),
        right((-0.125)->em),
        verticalAlign(`baseline),
        zIndex(-1),
        backgroundColor(hex("f2cc6c")),
        transform(scaleY(0.)),
        transformOrigin(50.->pct, 100.->pct),
        transitionProperty("transform"),
        transitionDuration(250),
        transitionTimingFunction(`ease),
      ]),
      Media.isHover([before([transform(scaleY(0.4))])]),
      Media.isMd([marginLeft(32->px), marginRight(0->px)]),
    ]);

  let row = style([Media.isMd([flexDirection(`row)])]);

  let introContainer =
    style([
      paddingTop(32->px),
      paddingBottom(64->px),
      Media.isMd([flex(4), paddingTop(6.5->vw), paddingBottom(12.->vw)]),
      Media.isXl([paddingTop(80->px), paddingBottom(140->px)]),
    ]);

  let introTitle =
    merge([title, style([fontSize(48->px), marginBottom(16->px)])]);

  let imageContainer =
    style([
      marginLeft((-72)->px),
      marginRight((-72)->px),
      marginBottom((-2.5)->vw),
      Media.isMd([
        flex(6),
        marginLeft(0->px),
        marginRight((-7.5)->vw),
        marginBottom((-1.5)->vw),
      ]),
      Media.isXl([
        marginLeft(72->px),
        marginRight((-88)->px),
        marginBottom((-16)->px),
      ]),
    ]);

  let image =
    style([
      Media.isMd([
        position(`absolute),
        bottom(0->px),
        right(0->px),
        maxHeight(384->px),
      ]),
    ]);

  let page = style([paddingTop(48->px), Media.isMd([paddingTop(64->px)])]);

  let section = style([marginBottom(48->px)]);

  let sectionTitle =
    merge([title, style([fontSize(32->px), marginBottom(16->px)])]);

  let tools =
    style([
      unsafe("WebkitOverflowScrolling", "touch"),
      unsafe("scrollSnapType", "x mandatory"),
      Media.isMd([paddingLeft(16->px), paddingRight(16->px)]),
    ]);

  let tool =
    style([
      alignItems(`center),
      color(Theme.textColor),
      display(`flex),
      flexDirection(`column),
      borderRadius(8->px),
      textDecoration(`none),
      paddingLeft(16->px),
      unsafe("scrollSnapAlign", "start"),
    ]);

  let toolLogo =
    style([
      borderRadius(8->px),
      height(96->px),
      width(96->px),
      transforms([scaleX(1.), scaleY(1.)]),
      transformOrigin(50.->pct, 50.->pct),
      transitionProperty("transform"),
      transitionDuration(250),
      transitionTimingFunction(`easeIn),
      Media.isHover([transforms([scaleX(0.95), scaleY(0.95)])]),
    ]);

  let toolName = style([marginTop(8->px)]);
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
        <View className={Css.merge([Styles.container, Styles.block])}>
          <View role=Banner className=Styles.header>
            <h1 className=Styles.siteTitle>
              {React.string(Content.siteTitle)}
            </h1>
            <View role=Navigation className=Styles.menuNav>
              <View role=List className=Styles.menuList>
                <View role=ListItem>
                  <Link
                    href={"mailto:" ++ self.state.email}
                    className=Styles.menuLink>
                    {React.string("contact")}
                  </Link>
                </View>
                <View role=ListItem>
                  <Link href=Content.githubUrl className=Styles.menuLink>
                    {React.string("github")}
                  </Link>
                </View>
                <View role=ListItem>
                  <Link href=Content.twitterUrl className=Styles.menuLink>
                    {React.string("twitter")}
                  </Link>
                </View>
              </View>
            </View>
          </View>
          <View className=Styles.row>
            <View className=Styles.introContainer>
              <h1 className=Styles.introTitle>
                {React.string({js|Hello !|js})}
              </h1>
              <p className=Styles.text>
                {React.string(
                   "I am Mathieu Acthernoene (aka @zoontek), a front-end developer living in Paris, France. I currently work at BeOp, where we build a third-party solution for editors on the web, enabling them to create interactive.",
                 )}
              </p>
            </View>
            <View className=Styles.imageContainer>
              <img
                alt="website main illustration"
                src=illustration
                className=Styles.image
              />
            </View>
          </View>
        </View>
      </View>
      <View role=Main className={Css.merge([Styles.container, Styles.page])}>
        <View role=Region className=Styles.section>
          <h2 className={Css.merge([Styles.block, Styles.sectionTitle])}>
            {React.string("Things I work with")}
          </h2>
          <FlatList
            className={Css.merge([Styles.text, Styles.tools])}
            data=Content.tools
            horizontal=true
            keyExtractor={(_index, tool) => tool.name}
            renderItem={(index, tool) => {
              let logoStyle = Css.(style([backgroundColor(tool.bgColor)]));
              let isLast = Array.length(Content.tools) === index + 1;
              let style = Css.(style([paddingRight(px(isLast ? 16 : 0))]));

              <View role=ListItem className={Css.merge([Styles.tool, style])}>
                <Link href={tool.linkHref} className=Styles.flexed>
                  <img
                    src={tool.logoSrc}
                    className={Css.merge([Styles.toolLogo, logoStyle])}
                    alt={tool.name ++ " logo"}
                  />
                </Link>
                <span className=Styles.toolName>
                  {React.string(tool.name)}
                </span>
              </View>;
            }}
          />
        </View>
        <View
          role=Region className={Css.merge([Styles.block, Styles.section])}>
          <h2 className=Styles.sectionTitle>
            {React.string("Things I work on")}
          </h2>
          <View role=List className=Styles.text>
            <View
              role=ListItem
              className=Css.(
                style([maxWidth(496->px), marginBottom(16->px)])
              )>
              <View
                className=Css.(
                  style([
                    flexDirection(`row),
                    marginBottom(4->px),
                    alignItems(`center),
                  ])
                )>
                <img
                  src=scaleway
                  className=Css.(
                    style([
                      backgroundColor(hex("4F0599")),
                      marginRight(12->px),
                      borderRadius(8->px),
                      height(24->px),
                      width(24->px),
                    ])
                  )
                />
                <span
                  className=Css.(
                    style([fontWeight(`bold), color(Theme.titleColor)])
                  )>
                  {React.string({js|Scaleway control panel / 2018|js})}
                </span>
              </View>
              <p>
                {React.string(
                   {js|Franchement j'ai fait des trucs, c'était sympa c'était sympa c'était sympa c'était sympa c'était sympa.|js},
                 )}
              </p>
            </View>
            <View
              role=ListItem
              className=Css.(
                style([maxWidth(496->px), marginBottom(16->px)])
              )>
              <View
                className=Css.(
                  style([
                    flexDirection(`row),
                    marginBottom(4->px),
                    alignItems(`center),
                  ])
                )>
                <img
                  src=scaleway
                  className=Css.(
                    style([
                      backgroundColor(hex("4F0599")),
                      marginRight(12->px),
                      borderRadius(8->px),
                      height(24->px),
                      width(24->px),
                    ])
                  )
                />
                <span
                  className=Css.(
                    style([fontWeight(`bold), color(Theme.titleColor)])
                  )>
                  {React.string({js|Wulo mobile app / 2016 ↦ 2018|js})}
                </span>
              </View>
              <p>
                {React.string(
                   {js|Franchement j'ai fait des trucs, c'était sympa c'était sympa c'était sympa c'était sympa c'était sympa.|js},
                 )}
              </p>
            </View>
            <View
              role=ListItem
              className=Css.(
                style([maxWidth(496->px), marginBottom(16->px)])
              )>
              <View
                className=Css.(
                  style([
                    flexDirection(`row),
                    marginBottom(4->px),
                    alignItems(`center),
                  ])
                )>
                <img
                  src=scaleway
                  className=Css.(
                    style([
                      backgroundColor(hex("4F0599")),
                      marginRight(12->px),
                      borderRadius(8->px),
                      height(24->px),
                      width(24->px),
                    ])
                  )
                />
                <span
                  className=Css.(
                    style([fontWeight(`bold), color(Theme.titleColor)])
                  )>
                  {React.string({js|Colisweb mobile app / 2015 ↦ 2016|js})}
                </span>
              </View>
              <p>
                {React.string(
                   {js|Franchement j'ai fait des trucs, c'était sympa c'était sympa c'était sympa c'était sympa c'était sympa.|js},
                 )}
              </p>
            </View>
            <View
              role=ListItem
              className=Css.(
                style([maxWidth(40.->pct), marginBottom(16->px)])
              )>
              <View
                className=Css.(
                  style([
                    flexDirection(`row),
                    marginBottom(4->px),
                    alignItems(`center),
                  ])
                )>
                <img
                  src=scaleway
                  className=Css.(
                    style([
                      backgroundColor(hex("4F0599")),
                      marginRight(12->px),
                      borderRadius(8->px),
                      height(24->px),
                      width(24->px),
                    ])
                  )
                />
                <span
                  className=Css.(
                    style([fontWeight(`bold), color(Theme.titleColor)])
                  )>
                  {React.string({js|Onemore agency / 2012 ↦ 2015|js})}
                </span>
              </View>
              <p>
                {React.string(
                   {js|Franchement j'ai fait des trucs, c'était sympa c'était sympa c'était sympa c'était sympa c'était sympa.|js},
                 )}
              </p>
            </View>
          </View>
        </View>
        <View
          role=Region className={Css.merge([Styles.block, Styles.section])}>
          <h2 className=Styles.sectionTitle>
            {React.string("Activities I enjoy")}
          </h2>
          <View role=List className=Styles.text>
            <View role=ListItem> {React.string("Commuter bike")} </View>
            <View role=ListItem> {React.string("Swimming")} </View>
            <View role=ListItem> {React.string("Hiking")} </View>
            <View role=ListItem> {React.string("Podcasting")} </View>
            <View role=ListItem> {React.string("Climbing")} </View>
          </View>
        </View>
        <View
          role=Region className={Css.merge([Styles.block, Styles.section])}>
          <h2 className=Styles.sectionTitle>
            {React.string("Talks I gave")}
          </h2>
          <View role=List className=Styles.text>
            <View role=ListItem>
              {React.string(
                 "Modern services communication with gRPC @ ParisJS #74",
               )}
            </View>
            <View role=ListItem>
              {React.string(
                 "Enhance your JavaScript with Flow @ Algolia TechLunch #17, Take Off Talks #11/17",
               )}
            </View>
            <View role=ListItem>
              {React.string("Your first React Native app @ ChtiJS #16")}
            </View>
            <View role=ListItem>
              {React.string("Handle your app state with Redux @ ChtiJS #15")}
            </View>
            <View role=ListItem>
              {React.string("Electron presentation @ ChtiJS #14")}
            </View>
            <View role=ListItem>
              {React.string(
                 "React Motion: animations done right @ WelshDesign #7",
               )}
            </View>
          </View>
        </View>
      </View>
      <View
        role=ContentInfo
        className=Css.(
          merge([
            Styles.container,
            Styles.block,
            style([
              marginTop(16->px),
              paddingTop(16->px),
              paddingBottom(16->px),
              textAlign(`center),
              lineHeight(`abs(1.4)),
              fontSize(14->px),
              color(Theme.textColor),
              opacity(0.75),
            ]),
          ])
        )>
        <small>
          {React.string("website written using Reason & ReasonReact")}
        </small>
        <Link href="#">
          <small> {React.string("source available here")} </small>
        </Link>
      </View>
    </>,
};
