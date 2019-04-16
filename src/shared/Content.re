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

let introParagraphs = [|
  {js|I am Mathieu Acthernoene, also known as @zoontek, a front-end and mobile developer living in Paris, France.|js},
  {js|I enjoy using the React ecosystem, especially to develop iOS and Android native applications. I also like working on open source projects or giving public talks.|js},
|];

type tool = {
  name: string,
  bgColor: Css.color,
  logoSrc: string,
  href: string,
};

let tools = [|
  {
    name: "React",
    bgColor: Css.hex("53c1dd"),
    logoSrc: reactLogo,
    href: "https://reactjs.org",
  },
  // {
  //   name: "React Native",
  //   bgColor: Css.hex("323446"),
  //   logoSrc: reactLogo,
  //   href: "https://facebook.github.io/react-native",
  // },
  {
    name: "gRPC",
    bgColor: Css.hex("2da6b0"),
    logoSrc: grpcLogo,
    href: "https://grpc.io",
  },
  {
    name: "Jest",
    bgColor: Css.hex("cc5030"),
    logoSrc: jestLogo,
    href: "https://jestjs.io",
  },
  {
    name: "JavaScript",
    bgColor: Css.hex("f6df31"),
    logoSrc: jsLogo,
    href: "https://developer.mozilla.org/docs/Web/JavaScript",
  },
  {
    name: "TypeScript",
    bgColor: Css.hex("2687d1"),
    logoSrc: tsLogo,
    href: "https://www.typescriptlang.org",
  },
  {
    name: "Flow",
    bgColor: Css.hex("323446"),
    logoSrc: flowLogo,
    href: "https://flow.org",
  },
  {
    name: "Sketch",
    bgColor: Css.hex("323446"),
    logoSrc: sketchLogo,
    href: "https://www.sketchapp.com",
  },
|];

type experience = {
  title: string,
  description: string,
  href: option(string),
  bgColor: Css.color,
  logoElement: React.reactElement,
};

let experiences = [|
  {
    title: {js|Swan / 2019 ↦ Present|js},
    description: {js|A simple banking API for accounts, cards and IBANs on the fly.|js},
    href: Some("https://swan.io"),
    bgColor: Css.hex("212121"),
    logoElement:
      <svg height="24" width="24">
        <path
          d="M13.52 18.45h-2.1c-3.52 0-6.02-3.03-6.02-6.47a6.4 6.4 0 0 1 6.35-6.48c3.89 0 6.55 2.32 6.55 5.92v7.08h-2.27v-7.08c0-2.29-1.59-3.67-4.28-3.67a4.15 4.15 0 0 0-4.08 4.23c0 2.29 1.6 4.22 3.76 4.22h2.09v2.25z"
          fill="#fff"
          fillRule="evenodd"
        />
      </svg>,
  },
  {
    title: {js|Scaleway / 2018|js},
    description: {js|A brand new customer dashboard using React web technologies for the french cloud provider.|js},
    href: Some("https://www.scaleway.com"),
    bgColor: Css.hex("4f0599"),
    logoElement:
      <svg height="24" width="24">
        <g fill="#fff" fillRule="evenodd">
          <path
            d="M11.437 16.035h2.462c.54-.066.955-.511.981-1.055v-3.552a.854.854 0 0 0-1.708 0v2.257a.641.641 0 0 1-.64.641h-1.117a.854.854 0 0 0-.853.866.867.867 0 0 0 .875.843zM12.547 7.926h-2.463c-.54.065-.955.51-.981 1.054v3.551a.854.854 0 1 0 1.707 0v-2.256c0-.354.287-.641.641-.641h1.116a.854.854 0 0 0 .853-.865.867.867 0 0 0-.873-.843z"
          />
          <path
            d="M12.962 6.208a3.633 3.633 0 0 1 3.628 3.628v6.978a1.118 1.118 0 0 1-.958.92h-4.64a3.63 3.63 0 0 1-3.63-3.63V7.33c0-.62.502-1.122 1.122-1.122zm0-1.708H8.484a2.83 2.83 0 0 0-2.83 2.83v6.774a5.338 5.338 0 0 0 5.338 5.338h4.726a2.83 2.83 0 0 0 2.582-2.516v-7.09A5.336 5.336 0 0 0 12.962 4.5z"
            fillRule="nonzero"
          />
        </g>
      </svg>,
  },
  {
    title: {js|Wulo / 2016 ↦ 2018|js},
    description: {js|An on-demand taxi mobile application built using React Native.|js},
    href: Some("https://www.wulo.fr"),
    bgColor: Css.hex("11daeb"),
    logoElement:
      <svg height="24" width="24">
        <g fill="none" fillRule="evenodd">
          <path
            d="M5.648 7.772s-.44 8.262 1.089 8.409c1.535.146 4.813-8.55 4.813-8.55s-.563 8.464 1.143 8.599c1.707.134 4.098-4.917 4.098-4.917s1.755-3.578.244-3.615-1.42 3.706.227 3.706c1.097 0 1.93-.117 2.498-.35"
            stroke="#fff"
            strokeLinecap="round"
            strokeLinejoin="round"
            strokeWidth="2"
          />
          <path
            d="M15.59 11.522s.922.758 1.76.9l-.253.391s-1.172-.557-1.587-1.16z"
            fill="#000"
            opacity="0.1"
          />
        </g>
      </svg>,
  },
  {
    title: {js|Colisweb / 2015 ↦ 2016|js},
    description: {js|A management application for carriers allowing them to ensure less than 2h or on-demand deliveries.|js},
    href: Some("https://www.colisweb.com"),
    bgColor: Css.hex("1ecae1"),
    logoElement:
      <svg height="24" width="24">
        <g fill="#fff" fillRule="evenodd">
          <path
            d="M18.454 8.468a7.368 7.368 0 0 0-6.416-3.75A7.414 7.414 0 0 0 7.626 6.19a7.35 7.35 0 0 0-2.89 4.965l1.253-.637.03-.117a6.176 6.176 0 0 1 2.273-3.32 6.234 6.234 0 0 1 5.437-1.02 6.252 6.252 0 1 1-3.366 12.043 6.296 6.296 0 0 1-1.806-.83l-1.564.17a7.383 7.383 0 0 0 5.053 2.005 7.414 7.414 0 0 0 4.412-1.471 7.363 7.363 0 0 0 1.999-9.505z"
          />
          <path
            d="M6.728 15.37l-1.13.272.031.057c.109.192.221.377.349.558l1.087-.392a5.907 5.907 0 0 1-.337-.494zM5.85 12.953l-1.079.307c.058.353.141.702.25 1.043l1.003-.525a6.234 6.234 0 0 1-.174-.825z"
          />
          <path
            d="M13.171 13.976a1.48 1.48 0 0 1-.712.221c-.609.033-1.066-.121-1.37-.47a1.802 1.802 0 0 1-.377-1.41c.03-.548.25-1.068.624-1.47a2.082 2.082 0 0 1 1.458-.632c.233-.016.466.029.675.13.19.088.35.226.466.4L15.65 8.98a2.539 2.539 0 0 0-1.255-.739 4.65 4.65 0 0 0-1.434-.152 5.27 5.27 0 0 0-1.714.388 4.853 4.853 0 0 0-.717.364L.649 13.857l7.786-2.219a4.822 4.822 0 0 0-.134 1.573L4.024 15.45l4.566-1.103c.172.389.42.74.728 1.032.068.064.139.124.22.181l-4.131 1.498 6.646-.723h.245c.228-.013.454-.043.677-.09h.029c.257-.058.51-.132.759-.221.524-.19 1-.49 1.396-.883l-1.443-1.59c-.16.167-.344.31-.545.425z"
          />
        </g>
      </svg>,
  },
  {
    title: {js|Onemore / 2012 ↦ 2015|js},
    description: {js|A web agency created with friends. I was a designer back then.|js},
    href: None,
    bgColor: Css.hex("e75854"),
    logoElement:
      <svg height="24" width="24">
        <path
          d="M15.328 6.326c-.711-2.396-4.431-1.062-5.639.23-2.081 2.228-2.5 6.841-1.635 9.663.702 2.287 3.223 3.664 5.36 2.136 2.23-1.592 3.063-5.654 2.945-8.24-.038-.824-.225-2.783-1.264-2.972-.682-.124-1.544.644-1.652 1.291-.126.754.613 1.558.726 2.312.192 1.286-.112 2.952-.404 4.21-.174.75-.683 2.71-1.796 2.43-1.281-.325-1.303-2.887-1.263-3.903.122-3.123.832-7.125 4.622-7.157z"
          fill="#fff"
          fillRule="evenodd"
        />
      </svg>,
  },
|];

type activity = {
  name: string,
  iconElement: React.reactElement,
};

let activities = [|
  {
    name: "Hiking",
    iconElement:
      <svg height="22" width="22" viewBox="0 0 384 512">
        <path
          d="M80.95 472.23c-4.28 17.16 6.14 34.53 23.28 38.81 2.61.66 5.22.95 7.8.95 14.33 0 27.37-9.7 31.02-24.23l25.24-100.97-52.78-52.78-34.56 138.22zm14.89-196.12L137 117c2.19-8.42-3.14-16.95-11.92-19.06-43.88-10.52-88.35 15.07-99.32 57.17L.49 253.24c-2.19 8.42 3.14 16.95 11.92 19.06l63.56 15.25c8.79 2.1 17.68-3.02 19.87-11.44zM368 160h-16c-8.84 0-16 7.16-16 16v16h-34.75l-46.78-46.78C243.38 134.11 228.61 128 212.91 128c-27.02 0-50.47 18.3-57.03 44.52l-26.92 107.72a32.012 32.012 0 0 0 8.42 30.39L224 397.25V480c0 17.67 14.33 32 32 32s32-14.33 32-32v-82.75c0-17.09-6.66-33.16-18.75-45.25l-46.82-46.82c.15-.5.49-.89.62-1.41l19.89-79.57 22.43 22.43c6 6 14.14 9.38 22.62 9.38h48v240c0 8.84 7.16 16 16 16h16c8.84 0 16-7.16 16-16V176c.01-8.84-7.15-16-15.99-16zM240 96c26.51 0 48-21.49 48-48S266.51 0 240 0s-48 21.49-48 48 21.49 48 48 48z"
        />
      </svg>,
  },
  {
    name: "Bike commuting",
    iconElement:
      <svg height="22" width="22" viewBox="0 0 640 512">
        <path
          d="M512.509 192.001c-16.373-.064-32.03 2.955-46.436 8.495l-77.68-125.153A24 24 0 0 0 368.001 64h-64c-8.837 0-16 7.163-16 16v16c0 8.837 7.163 16 16 16h50.649l14.896 24H256.002v-16c0-8.837-7.163-16-16-16h-87.459c-13.441 0-24.777 10.999-24.536 24.437.232 13.044 10.876 23.563 23.995 23.563h48.726l-29.417 47.52c-13.433-4.83-27.904-7.483-42.992-7.52C58.094 191.83.412 249.012.002 319.236-.413 390.279 57.055 448 128.002 448c59.642 0 109.758-40.793 123.967-96h52.033a24 24 0 0 0 20.406-11.367L410.37 201.77l14.938 24.067c-25.455 23.448-41.385 57.081-41.307 94.437.145 68.833 57.899 127.051 126.729 127.719 70.606.685 128.181-55.803 129.255-125.996 1.086-70.941-56.526-129.72-127.476-129.996zM186.75 265.772c9.727 10.529 16.673 23.661 19.642 38.228h-43.306l23.664-38.228zM128.002 400c-44.112 0-80-35.888-80-80s35.888-80 80-80c5.869 0 11.586.653 17.099 1.859l-45.505 73.509C89.715 331.327 101.213 352 120.002 352h81.3c-12.37 28.225-40.562 48-73.3 48zm162.63-96h-35.624c-3.96-31.756-19.556-59.894-42.383-80.026L237.371 184h127.547l-74.286 120zm217.057 95.886c-41.036-2.165-74.049-35.692-75.627-76.755-.812-21.121 6.633-40.518 19.335-55.263l44.433 71.586c4.66 7.508 14.524 9.816 22.032 5.156l13.594-8.437c7.508-4.66 9.817-14.524 5.156-22.032l-44.468-71.643a79.901 79.901 0 0 1 19.858-2.497c44.112 0 80 35.888 80 80-.001 45.54-38.252 82.316-84.313 79.885z"
        />
      </svg>,
  },
  {
    name: "Swimming",
    iconElement:
      <svg height="22" width="22" viewBox="0 0 640 512">
        <path
          d="M189.61 310.58c3.54 3.26 15.27 9.42 34.39 9.42s30.86-6.16 34.39-9.42c16.02-14.77 34.5-22.58 53.46-22.58h16.3c18.96 0 37.45 7.81 53.46 22.58 3.54 3.26 15.27 9.42 34.39 9.42s30.86-6.16 34.39-9.42c14.86-13.71 31.88-21.12 49.39-22.16l-112.84-80.6 18-12.86c3.64-2.58 8.28-3.52 12.62-2.61l100.35 21.53c25.91 5.53 51.44-10.97 57-36.88 5.55-25.92-10.95-51.44-36.88-57L437.68 98.47c-30.73-6.58-63.02.12-88.56 18.38l-80.02 57.17c-10.38 7.39-19.36 16.44-26.72 26.94L173.75 299c5.47 3.23 10.82 6.93 15.86 11.58zM624 352h-16c-26.04 0-45.8-8.42-56.09-17.9-8.9-8.21-19.66-14.1-31.77-14.1h-16.3c-12.11 0-22.87 5.89-31.77 14.1C461.8 343.58 442.04 352 416 352s-45.8-8.42-56.09-17.9c-8.9-8.21-19.66-14.1-31.77-14.1h-16.3c-12.11 0-22.87 5.89-31.77 14.1C269.8 343.58 250.04 352 224 352s-45.8-8.42-56.09-17.9c-8.9-8.21-19.66-14.1-31.77-14.1h-16.3c-12.11 0-22.87 5.89-31.77 14.1C77.8 343.58 58.04 352 32 352H16c-8.84 0-16 7.16-16 16v32c0 8.84 7.16 16 16 16h16c38.62 0 72.72-12.19 96-31.84 23.28 19.66 57.38 31.84 96 31.84s72.72-12.19 96-31.84c23.28 19.66 57.38 31.84 96 31.84s72.72-12.19 96-31.84c23.28 19.66 57.38 31.84 96 31.84h16c8.84 0 16-7.16 16-16v-32c0-8.84-7.16-16-16-16zm-512-96c44.18 0 80-35.82 80-80s-35.82-80-80-80-80 35.82-80 80 35.82 80 80 80z"
        />
      </svg>,
  },
  {
    name: "Podcasting",
    iconElement:
      <svg height="22" width="22" viewBox="0 0 448 512">
        <path
          d="M267.429 488.563C262.286 507.573 242.858 512 224 512c-18.857 0-38.286-4.427-43.428-23.437C172.927 460.134 160 388.898 160 355.75c0-35.156 31.142-43.75 64-43.75s64 8.594 64 43.75c0 32.949-12.871 104.179-20.571 132.813zM156.867 288.554c-18.693-18.308-29.958-44.173-28.784-72.599 2.054-49.724 42.395-89.956 92.124-91.881C274.862 121.958 320 165.807 320 220c0 26.827-11.064 51.116-28.866 68.552-2.675 2.62-2.401 6.986.628 9.187 9.312 6.765 16.46 15.343 21.234 25.363 1.741 3.654 6.497 4.66 9.449 1.891 28.826-27.043 46.553-65.783 45.511-108.565-1.855-76.206-63.595-138.208-139.793-140.369C146.869 73.753 80 139.215 80 220c0 41.361 17.532 78.7 45.55 104.989 2.953 2.771 7.711 1.77 9.453-1.887 4.774-10.021 11.923-18.598 21.235-25.363 3.029-2.2 3.304-6.566.629-9.185zM224 0C100.204 0 0 100.185 0 224c0 89.992 52.602 165.647 125.739 201.408 4.333 2.118 9.267-1.544 8.535-6.31-2.382-15.512-4.342-30.946-5.406-44.339-.146-1.836-1.149-3.486-2.678-4.512-47.4-31.806-78.564-86.016-78.187-147.347.592-96.237 79.29-174.648 175.529-174.899C320.793 47.747 400 126.797 400 224c0 61.932-32.158 116.49-80.65 147.867-.999 14.037-3.069 30.588-5.624 47.23-.732 4.767 4.203 8.429 8.535 6.31C395.227 389.727 448 314.187 448 224 448 100.205 347.815 0 224 0zm0 160c-35.346 0-64 28.654-64 64s28.654 64 64 64 64-28.654 64-64-28.654-64-64-64z"
        />
      </svg>,
  },
|];

type talk = {
  title: string,
  event: string,
  href: option(string),
};

let talks = [|
  {
    title: {js|Modern services communication with gRPC|js},
    event: "ParisJS #74",
    href:
      Some(
        "https://speakerdeck.com/zoontek/manage-microservices-like-a-chef",
      ),
  },
  {
    title: {js|Enhance your JavaScript with Flow|js},
    event: "Algolia TechLunch #17, Take Off Talks #11/17",
    href: None,
  },
  {
    title: {js|Your first React Native app|js},
    event: "ChtiJS #16",
    href: Some("https://slides.com/zoontek/react-native"),
  },
  {
    title: {js|Handle your app state with Redux|js},
    event: "ChtiJS #15",
    href: Some("https://slides.com/zoontek/redux"),
  },
  {
    title: {js|Electron presentation|js},
    event: "ChtiJS #14",
    href: Some("https://slides.com/zoontek/electron"),
  },
  {
    title: {js|React Motion: animations done right|js},
    event: "WelshDesign #7",
    href: Some("https://slides.com/zoontek/react-motion"),
  },
|];
