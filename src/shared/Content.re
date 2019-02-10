[@bs.module] external reactLogo: string = "../static/media/react.svg";
[@bs.module] external jestLogo: string = "../static/media/jest.svg";
[@bs.module] external grpcLogo: string = "../static/media/grpc.svg";
[@bs.module] external flowLogo: string = "../static/media/flow.svg";
[@bs.module] external jsLogo: string = "../static/media/javascript.svg";
[@bs.module] external tsLogo: string = "../static/media/typescript.svg";
[@bs.module] external sketchLogo: string = "../static/media/sketch.svg";

let siteTitle = "@zoontek";
let emailAddress = "zoontek@gmail.com";
let githubUrl = "https://github.com/zoontek";
let twitterUrl = "https://twitter.com/zoontek";

type tool = {
  name: string,
  bgColor: Css.color,
  logoSrc: string,
  linkHref: string,
};

let tools = [|
  {
    name: "React",
    bgColor: Css.hex("53c1dd"),
    logoSrc: reactLogo,
    linkHref: "https://reactjs.org",
  },
  {
    name: "Jest",
    bgColor: Css.hex("cc5030"),
    logoSrc: jestLogo,
    linkHref: "https://jestjs.io",
  },
  {
    name: "gRPC",
    bgColor: Css.hex("2da6b0"),
    logoSrc: grpcLogo,
    linkHref: "https://grpc.io",
  },
  {
    name: "Flow",
    bgColor: Css.hex("323446"),
    logoSrc: flowLogo,
    linkHref: "https://flow.org",
  },
  {
    name: "JavaScript",
    bgColor: Css.hex("f7e141"),
    logoSrc: jsLogo,
    linkHref: "https://developer.mozilla.org/docs/Web/JavaScript",
  },
  {
    name: "TypeScript",
    bgColor: Css.hex("2687d1"),
    logoSrc: tsLogo,
    linkHref: "https://www.typescriptlang.org",
  },
  {
    name: "Sketch",
    bgColor: Css.hex("323446"),
    logoSrc: sketchLogo,
    linkHref: "https://www.sketchapp.com",
  },
|];
