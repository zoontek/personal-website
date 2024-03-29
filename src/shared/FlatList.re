open Belt;

let component = React.statelessComponent("FlatList");

module Styles = {
  open Css;

  let horizontal = style([flexDirection(`row), overflowY(`auto)]);
  let vertical = style([flexDirection(`column), overflowX(`auto)]);
};

let make =
    (
      ~className=?,
      ~data,
      ~horizontal=false,
      ~keyExtractor,
      ~renderItem,
      ~separatorElement=?,
      _children,
    ) => {
  ...component,
  render: _self => {
    let separatorElement =
      separatorElement->Option.getWithDefault(React.null);
    let baseStyle = horizontal ? Styles.horizontal : Styles.vertical;
    let className = className->Option.getWithDefault("");

    <View role=List className={Css.merge([baseStyle, className])}>
      {React.array(
         Array.mapWithIndex(
           data,
           (i, item) => {
             let separatorElement =
               Array.length(data) === i + 1 ? React.null : separatorElement;

             React.createElement(
               React.fragment,
               ~props={"key": keyExtractor(i, item)},
               [|renderItem(i, item), separatorElement|],
             );
           },
         ),
       )}
    </View>;
  },
};
