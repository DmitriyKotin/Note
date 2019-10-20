import Felgo 3.0
import QtQuick 2.12


App {
  // You get free licenseKeys from https://felgo.com/licenseKey
  // With a licenseKey you can:
  //  * Publish your games & apps for the app stores
  //  * Remove the Felgo Splash Screen or set a custom one (available with the Pro Licenses)
  //  * Add plugins to monetize, analyze & improve your apps (available with the Pro Licenses)
  //licenseKey: "<generate one from https://felgo.com/licenseKey>"

  //  NavigationStack {

  //    Page {
  //      title: qsTr("Main Page")

  //      Image {
  //        source: "../assets/felgo-logo.png"
  //        anchors.centerIn: parent
  //      }
  //    }

  //  }

  Navigation {
    id: navigation

    NavigationItem {
      title: qsTr("Заметки")
      icon: IconType.list

      NavigationStack {
        id: stack

        splitView: tablet // use side-by-side view on tablets
        initialPage: TreePage {

          onItemSelected: {
            if (!item.isFolder()) {
              Presenter.setNode(item)

              var component = Qt.createComponent(item.qmlPage)
              stack.push(component.createObject(stack,
                                                {isCreate: false,
                                                  node: item,
                                                  icon: item.bigIcon}))
            }
            else {
              Presenter.selectFolder(item)
            }
          }


          contextMenu.onCreateAccount: {
            var component = Qt.createComponent("AccountPage.qml")
            stack.push(component.createObject(stack, {isCreate: true}))
          }

          contextMenu.onCreateBankCard: {
            var component = Qt.createComponent("BankCardPage.qml")
            stack.push(component.createObject(stack, {isCreate: true}))
          }

          contextMenu.onCreateContact: {
            var component = Qt.createComponent("ContactPage.qml")
            stack.push(component.createObject(stack, {isCreate: true}))
          }

          contextMenu.onCreateMemo: {
            var component = Qt.createComponent("MemoPage.qml")
            stack.push(component.createObject(stack, {isCreate: true}))
          }

        }
      }
    }

    // second tab
    NavigationItem {
      title: qsTr("Поиск") // use qsTr for strings you want to translate
      icon: IconType.search

      NavigationStack {
        initialPage: ContactPage {}
        //          // handle logout
        //          onLogoutClicked: {
        //            logic.logout()

        //            // jump to main page after logout
        //            navigation.currentIndex = 0
        //            navigation.currentNavigationItem.navigationStack.popAllExceptFirst()
        //          }
        //        }
      }
    }
  }



}







//Navigation {
//  id: navigation

//  // only enable if user is logged in
//  // login page below overlays navigation then
//  enabled: dataModel.userLoggedIn

//  // first tab
//  NavigationItem {
//    title: qsTr("Todo List")
//    icon: IconType.list

//    NavigationStack {
//      splitView: tablet // use side-by-side view on tablets
//      initialPage: TodoListPage { }
//    }
//  }

//  // second tab
//  NavigationItem {
//    title: qsTr("Profile") // use qsTr for strings you want to translate
//    icon: IconType.circle

//    NavigationStack {
//      initialPage: ProfilePage {
//        // handle logout
//        onLogoutClicked: {
//          logic.logout()

//          // jump to main page after logout
//          navigation.currentIndex = 0
//          navigation.currentNavigationItem.navigationStack.popAllExceptFirst()
//        }
//      }
//    }
//  }
//}
