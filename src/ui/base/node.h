#ifndef NODE_H
#define NODE_H

#include <QtDebug>
#include <QObject>
#include <QJSValue>
#include <QJSEngine>
#include <QQmlEngine>
#include <QLinkedList>
#include <QJSValueIterator>

#include "src/objects/invoke.h"
#include "src/ui/rendersynchronizer.h"

using namespace Quite::Objects;
using namespace Quite::Ui;

namespace Quite {
namespace Ui {
namespace Base {

/*****************************************************************************/

enum NodeType : int {
    NeverType = -1,
    ComponentType = 0,
    FragmentType = 1,
    ButtonType = 2,
    WindowType = 3,
    RectangleType = 4
};

/*****************************************************************************/

/*
 * Класс осуществляет базовый контейнер для описания элемента
 * на стороне JavaScript для передачи на рендеринг в QML
 */
class Node : public QObject{
  Q_OBJECT
  private:
    QMap<QString, QJSValue> props;
    QLinkedList<Node*> child;
    int totalChildCount = 1;
    QJSValue context;
    NodeType type;
    int key=0;
  public:
    explicit Node(QJSValue type, QJSValue props, QJSValue child);
    ~Node();

  private:
    void subscribeChildNode(Node* node);

  /*
   * Отдельный слот для удаления ноды в порядке diff изменений
   */
  public:
    void deleteNodeDiff();

  /*
   * Слоты управления древом под-нод
   */
  public slots:
    void appendChild(Node* child);
    void insertAfterChild(Node* after, Node* child);
  private slots:
    void childDeletedHandler(QObject* child);

  /*
   * Слоты управления свойствами ноды
   */
  public slots:
    void mergeProps(Node* node);
    void commitProps(bool merge=false);
    virtual void updateContext(QJSValue context, bool recursive = true);
    void updateChildContext(QJSValue context);

  /*
   * Геттеры, сеттеры
   */
  public:
    QMap<QString,QJSValue> getProps() const;
    QLinkedList<Node*> getChild() const;
    int getTotalChildCount() const;
    NodeType getEnumType() const;
    int getType() const;
    int getKey() const;

  /*
   * Методы для типизации объектов JS в нативные структуры данных
   */
  public:
    static QMap<QString, QJSValue> castNodeParams(QJSValue props);
    static QLinkedList<Node*> castNodeList(QJSValue src);
    static bool tryCastNode(QJSValue src, Node*& dst);
    static NodeType castNodeType(QString type);

  /*
   * Сигналы для прослушки со стороны Элементов
   */
  signals:
    void propsChanged(QMap<QString, QVariant> commitProps, bool merge);
    void childInsertedAfter(Node* after, Node* child);
    void childAppended(Node* child);

  /*
   * Управление колличеством дочерних нод
   */
  private slots:
    void incrementTotalChildCountHandler();
    void decrementTotalChildCountHandler();

  /*
   * Управление колличеством дочерних нод
   * Сигнал удаления с пометкой декремента diff счетчика
   */
  signals:
    void incrementTotalChildCount();
    void decrementTotalChildCount();
    void diffDelete();
};

/*****************************************************************************/

} // namespace Base
} // namespace Ui
} // namespace Quite

#endif // NODE_H
