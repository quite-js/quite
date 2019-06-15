#ifndef TIMEREXTENSION_H
#define TIMEREXTENSION_H

#include <QtDebug>
#include <QObject>
#include <QJSValue>
#include <QJSEngine>
#include <QJSValueIterator>

#include "base/extension.h"
#include "events/timerawait.h"

using namespace Quite::Base;

namespace Quite {
namespace Extensions {

/*****************************************************************************/

class TimerExtension : public Extension {
  Q_OBJECT
  public:
    explicit TimerExtension(QObject* parent = nullptr);
    virtual ~TimerExtension();
    virtual void install(QJSValue global, QJSValue current);
  public slots:
    QJSValue setTimeout(QJSValue handler, QJSValue timeout);
};

/*****************************************************************************/

} // namespace Extensions
} // namespace Quite

#endif // TIMEREXTENSION_H
