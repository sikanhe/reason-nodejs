open Jest;

describe("EventEmitter", () => {
  test(
    "'Emitter.make' should create a new emitter instance that is defined", () => {
    open! ExpectJs;
    open! EventEmitterTestLib;
    let emitter = Emitter1.make();
    expect(emitter->Js.Undefined.return) |> toBeDefined;
  });

  test("'Emitter.addListener' should add a new event listener", () => {
    open! ExpectJs;
    open! EventEmitterTestLib;
    let listeners =
      Emitter1.(
        {
          make()->addListener(Events.text, _ => ())->listeners(Events.text);
        }
      );
    expect(Array.length(listeners)) |> toBe(1);
  });

  test("'Emitter.on' should add a new event listener", () => {
    open! ExpectJs;
    open! EventEmitterTestLib;
    let listeners =
      Emitter1.(
        {
          make()->on(Events.text, _ => ())->listeners(Events.text);
        }
      );
    expect(Array.length(listeners)) |> toBe(1);
  });

  test("'Emitter.on' should add a new event listener", () => {
    open! ExpectJs;
    open! EventEmitterTestLib;
    let listeners =
      Emitter1.(
        {
          make()->on(Events.text, _ => ())->listeners(Events.text);
        }
      );
    expect(Array.length(listeners)) |> toBe(1);
  });

  test("'Emitter.removeListener' should remove the event listener", () => {
    open! ExpectJs;
    open! EventEmitterTestLib;
    let eventListener = (_) => ();
    let listeners =
      Emitter1.(
        {
          make()
            |> on(_, Events.text, eventListener)
            |> removeListener(_, Events.text, eventListener)
            |> listeners(_, Events.text);
        }
      );
    expect(Array.length(listeners)) |> toBe(0);
  });

  test("'Emitter.off' should remove the event listener", () => {
    open! ExpectJs;
    open! EventEmitterTestLib;
    let eventListener = (_) => ();
    let listeners =
      Emitter1.(
        {
          make()
            |> on(_, Events.text, eventListener)
            |> off(_, Events.text, eventListener)
            |> listeners(_, Events.text);
        }
      );
    expect(Array.length(listeners)) |> toBe(0);
  });

  test("'Emitter.emit' should execute each listener for the correct event", () => {
    open! ExpectJs;
    open! EventEmitterTestLib;
    let ref1 = ref(0);
    let ref2 = ref(0);
    let data1 = 1;
    let data2 = 2;
    let listener1 = (_) => { ref1 := data1; };
    let listener2 = (_) => { ref2 := data2; };
    Emitter1.({
        let emitter =
          make()
          |> on(_, Events.integer, listener1)
          |> on(_, Events.integer, listener2);
          emit(emitter, Events.integer, data1)->ignore;
          emit(emitter, Events.integer, data2)->ignore;
    });
    Assert.strictEqual(ref1^, 1);
    Assert.strictEqual(ref2^, 2);
    expect(ref1^ === 1 && ref2^ === 2) |> toBe(true);
  });

  test("'Emitter.removeAllListeners' should remove all event listeners", () => {
    open! ExpectJs;
    open! EventEmitterTestLib;
    let eventListener = (_) => ();
    let emitter =
      Emitter1.(
        {
          make()
            |> on(_, Events.text, eventListener)
            |> on(_, Events.text, eventListener)
            |> on(_, Events.text, eventListener)
        }
      );
    // Make sure 3 listeners were indeed added:
    Assert.strictEqual(Emitter1.(listeners(emitter, Events.text))->Array.length, 3);
    // Remove all the listeners:
    Emitter1.removeAllListeners(emitter)->ignore;
    expect(Emitter1.(listeners(emitter, Events.text))->Array.length) |> toBe(0);
  });

});
