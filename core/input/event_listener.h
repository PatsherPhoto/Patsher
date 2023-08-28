#ifndef EVENT_LISTENER_H
#define EVENT_LISTENER_H


#include "core/object/object.h"
#include "core/config/list.h"
#include "core/object/ref.h"
#include "core/input/event.h"
#include "core/string/string.h"


#include <functional>
#include <map>
#include <unordered_map>
#include <vector>

class Listener;
class SystemDB;

class EventListener : public Object {
    GGClass(EventListener, Object)
   
   enum ListenerMode {
        EVENT_PRESSED,
        EVENT_UP,
        EVENT_DOWN,
        EVENT_ON,
        EVENT_OFF
   };
  enum Mode {
     NORMAL,
     ONCE
  };
  // Event NameSpace with using Struct
 struct Event {
     std::string name;
     std::vector<int> data;
 };
 // new Event to Local event Listener
 using EventCallBack = std::function<void(const Event&)>;
// void EventCallBack & functionals && API
 void subs(const EventCallBack& p_call, Mode mode = Mode::NORMAL);
 void unsub(const EventCallBack& p_call);
 void notify(const EventCallBack& p_call);
 void set(const String& p_key);
 bool get(const String& p_key);
 bool on_lisent(const Listener& p_key);
 bool is_lisent(const Listener& p_is_key);
 void storeEvent(std::string& name, std::vector<int>& data);
 bool getEvent(std::string& name, const Event& p_event);
 // new event void to set and get event keys with using string
 void setEventWithStr(std::string& key, const Event& p_event);
 bool getEventWithStr(std::string& key, const Event& p_event); 
 // new void to rigister key with string
 void rigisterListener(std::string& key, const EventCallBack& call, Mode mode = Mode::NORMAL);

private:
    struct EventSub {
        EventCallBack call;
        Mode mode;
    };
    // 
using EventList = std::vector<EventSub>;
std::map<std::string EventList> EventMap;
std::map<std::string Event> storeEvent;
unorder_map<std::string, EventCallBack> keyEventList;



};


#endif // EVENT_LISTENER_H