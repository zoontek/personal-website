[@bs.module "emotion-server"]
external renderStylesToString: string => string = "renderStylesToString";

let html = renderStylesToString(ReactDOMServerRe.renderToString(<App />));
