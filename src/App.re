open Belt;

[@bs.module] external illustration: string = "./static/media/illustration.svg";

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
      Media.whenMd([paddingLeft(32->px), paddingRight(32->px)]),
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

  let smallTitle =
    style([
      display(`flex),
      fontSize(Theme.baseFontSize),
      color(Theme.titleColor),
      lineHeight(`abs(1.4)),
      fontWeight(`bold),
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
      Media.whenMd([
        alignItems(`center),
        flexDirection(`row),
        justifyContent(`spaceBetween),
      ]),
    ]);

  let menuNav =
    style([
      marginTop(8->px),
      flexShrink(1),
      Media.whenMd([marginTop(0->px)]),
    ]);

  let menuList =
    style([
      flexDirection(`row),
      flexWrap(`wrap),
      textTransform(`uppercase),
      Media.whenMd([justifyContent(`flexEnd)]),
    ]);

  let menuLink =
    style([
      color(Theme.textColor),
      position(`relative),
      textDecoration(`none),
      zIndex(1),
      letterSpacing(`normal),
      opacity(0.9),
      marginRight(16->px),
      after([
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
      Media.whenHover([after([transform(scaleY(0.4))])]),
      Media.whenMd([marginLeft(32->px), marginRight(0->px)]),
    ]);

  let row = style([Media.whenMd([flexDirection(`row)])]);

  let introContainer =
    style([
      paddingTop(32->px),
      paddingBottom(56->px),
      Media.whenMd([flex(4), paddingTop(6.5->vw), paddingBottom(12.->vw)]),
      Media.whenXl([paddingTop(80->px), paddingBottom(132->px)]),
    ]);

  let introTitle = merge([title, style([fontSize(48->px)])]);

  let introParagraph = merge([text, style([marginBottom(8->px)])]);

  let imageContainer =
    style([
      marginLeft((-72)->px),
      marginRight((-72)->px),
      marginBottom((-2.5)->vw),
      Media.whenMd([
        flex(6),
        marginLeft(0->px),
        marginRight((-7.5)->vw),
        marginBottom((-1.5)->vw),
      ]),
      Media.whenXl([
        marginLeft(72->px),
        marginRight((-88)->px),
        marginBottom((-16)->px),
      ]),
    ]);

  let image =
    style([
      Media.whenMd([
        position(`absolute),
        bottom(0->px),
        right(0->px),
        maxHeight(384->px),
      ]),
    ]);

  let page =
    style([paddingTop(48->px), Media.whenMd([paddingTop(64->px)])]);

  let sectionTitle = merge([title, style([fontSize(32->px)])]);

  let tools =
    style([
      unsafe("WebkitOverflowScrolling", "touch"),
      unsafe("scrollSnapType", "x mandatory"),
      Media.whenMd([paddingLeft(16->px), paddingRight(16->px)]),
    ]);

  let toolItem = last =>
    style([
      alignItems(`center),
      color(Theme.textColor),
      display(`flex),
      flexDirection(`column),
      borderRadius(8->px),
      textDecoration(`none),
      paddingLeft(16->px),
      paddingRight(px(last ? 16 : 0)),
      unsafe("scrollSnapAlign", "start"),
    ]);

  let toolLogo = bgColor =>
    style([
      backgroundColor(bgColor),
      borderRadius(6->px),
      height(80->px),
      width(80->px),
      transforms([scaleX(1.), scaleY(1.)]),
      transformOrigin(50.->pct, 50.->pct),
      transitionProperty("transform"),
      transitionDuration(250),
      transitionTimingFunction(`easeIn),
      Media.whenHover([transforms([scaleX(0.95), scaleY(0.95)])]),
    ]);

  let toolName =
    style([fontSize(14->px), marginTop(6->px), marginBottom(16->px)]);

  let corporateItem = style([maxWidth(546->px)]);

  let itemLine =
    style([alignItems(`center), flexDirection(`row), marginBottom(4->px)]);

  let corporateLogo = bgColor =>
    style([
      backgroundColor(bgColor),
      borderRadius(6->px),
      height(24->px),
      width(24->px),
    ]);

  let corporateLink =
    merge([smallTitle, style([display(`flex), textDecoration(`none)])]);

  let footer =
    merge([
      container,
      block,
      style([
        paddingTop(16->px),
        paddingBottom(16->px),
        textAlign(`center),
        lineHeight(`abs(1.4)),
        fontSize(14->px),
        color(Theme.textColor),
        opacity(0.75),
      ]),
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
        <View className={Css.merge([Styles.container, Styles.block])}>
          <View role=Banner className=Styles.header>
            <h1 className=Styles.smallTitle>
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
              <span className=Styles.introTitle>
                {React.string({js|Hello !|js})}
              </span>
              <Space h=16 />
              {React.array(
                 Array.mapWithIndex(Content.introParagraphs, (i, content) =>
                   <p
                     key={"intro-p-" ++ string_of_int(i)}
                     className=Styles.introParagraph>
                     {React.string(content)}
                   </p>
                 ),
               )}
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
        <View role=Region>
          <h2 className={Css.merge([Styles.block, Styles.sectionTitle])}>
            {React.string("Things I work with")}
          </h2>
          <Space h=24 />
          <FlatList
            className={Css.merge([Styles.text, Styles.tools])}
            data=Content.tools
            horizontal=true
            keyExtractor={(_i, tool) => tool.name}
            renderItem={(i, tool) => {
              let isLast = Array.length(Content.tools) === i + 1;

              <View role=ListItem className={Styles.toolItem(isLast)}>
                <Link href={tool.href} className=Styles.flexed>
                  <img
                    className={Styles.toolLogo(tool.bgColor)}
                    src={tool.logoSrc}
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
        <Space h=32 />
        <View role=Region className=Styles.block>
          <h2 className=Styles.sectionTitle>
            {React.string("Things I worked on")}
          </h2>
          <Space h=24 />
          <FlatList
            className=Styles.text
            data=Content.experiences
            separatorElement={<Space h=24 />}
            keyExtractor={(_i, xp) => xp.title}
            renderItem={(_i, xp) =>
              <View role=ListItem className=Styles.corporateItem>
                <View className=Styles.itemLine>
                  <View className={Styles.corporateLogo(xp.bgColor)}>
                    {xp.logoElement}
                  </View>
                  <Space w=12 />
                  {switch (xp.href) {
                   | Some(href) =>
                     <Link href className=Styles.corporateLink>
                       {React.string(xp.title)}
                     </Link>
                   | None =>
                     <span className=Styles.corporateLink>
                       {React.string(xp.title)}
                     </span>
                   }}
                </View>
                <p> {React.string(xp.description)} </p>
              </View>
            }
          />
        </View>
        <Space h=48 />
        <View role=Region className=Styles.block>
          <h2 className=Styles.sectionTitle>
            {React.string("Activities I enjoy")}
          </h2>
          <Space h=24 />
          <FlatList
            className=Styles.text
            data=Content.activities
            keyExtractor={(_i, activity) => activity.name}
            renderItem={(_i, activity) =>
              <View role=ListItem className=Styles.itemLine>
                {activity.iconElement}
                <Space w=12 />
                {React.string(activity.name)}
              </View>
            }
          />
        </View>
        <Space h=48 />
        <View role=Region className=Styles.block>
          <h2 className=Styles.sectionTitle>
            {React.string("Talks I gave")}
          </h2>
          <Space h=24 />
          <FlatList
            className=Styles.text
            data=Content.talks
            keyExtractor={(_i, talk) => talk.title}
            renderItem={(_i, talk) =>
              <li className=Styles.itemLine>
                <span ariaHidden=true> {React.string({js|▸ |js})} </span>
                {switch (talk.href) {
                 | Some(href) =>
                   <Link href className=Styles.text>
                     {React.string(talk.title)}
                   </Link>
                 | None =>
                   <span className=Styles.text>
                     {React.string(talk.title)}
                   </span>
                 }}
                {React.string(" @ " ++ talk.event)}
              </li>
            }
          />
        </View>
        <Space h=56 />
      </View>
      <View role=ContentInfo className=Styles.footer>
        <small>
          {React.string({js|website written using Reason & ReasonReact|js})}
        </small>
      </View>
      // <small>
      //   {React.string(
      //      {js|website written using Reason & ReasonReact • |js},
      //    )}
      //   <Link href="#" className=Css.(style([color(Theme.textColor)]))>
      //     {React.string("source available here")}
      //   </Link>
      // </small>
    </>,
};
