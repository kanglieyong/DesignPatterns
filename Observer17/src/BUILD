cc_library(
  name = "ConcreteObserver1",
  #srcs = ["ConcreteObserver1.cpp"],
  hdrs = ["IObserver.h", "ConcreteObserver1.h"],
  copts= ["-std=c++17"],
)

cc_library(
  name = "ConcreteObserver2",
  #srcs = ["ConcreteObserver2.cpp"],
  hdrs = ["IObserver.h", "ConcreteObserver2.h"],
  copts= ["-std=c++17"],
)

cc_library(
  name = "ObservableSubject",
  #srcs = ["ObservableSubject.cpp"],
  hdrs = ["ObservableSubject.h", "IObservable.h", "IObserver.h"],
  copts= ["-std=c++17"],
)

cc_binary(
  name = "a.out",
  srcs = ["main.cpp"],
  copts= ["-std=c++17"],
  deps = [
    ":ObservableSubject",
    ":ConcreteObserver1",
    ":ConcreteObserver2",
  ],
)
