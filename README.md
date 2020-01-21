
```shell
yarn install reason-nodejs
```

### Goal of this library

Help all Reason Node.js apps and libaries to be built faster by reducing the time spent on hand written bindings.

### Non-Goals

- Have 100% coverage of Node.js api surface - Due to lack of man power for testing and maintaining, we should only have enough surface
  to cover all common use cases. But we should have enough coverage that developers only rarely have to write a custom binding. 
- Ensure all APIs are idiomatic Reason and 100% typesafe - This library should be as barebones as possible to allow for minimal context switching between offical Node.js documentation and the Reason equilvalent. And due to the dynamic nature of the JS API, bending it to be idiomatic Reason will lead to a ton of bikeshedding in design as well as sacrificing maintainability.

### Principles

- When available, we prefer to bind to the promise version of the library instead of the callback version to reduce binding surface.
- Use subtyping only where the benefit is huge. We use subtyping for various APIs that implement Node Streams, such as HTTP Request and Response, FileSystem streams, Crypto streams, and etc. It allow us to use a single set of functions to manipulate and combine streams across different modules. For example: 

  ##### Stream a file into stdout: 
  ```reason
    Fs.createReadStream("/path")
    ->Stream.pipe(Process.stdout)
    ->Stream.onError(_ => Js.log("handleError"))
  ```
  ##### Echo server
  ```reason
  Http.createServer((request, response) => {
    request
    ->Stream.pipe(response)
    ->Stream.onData(data => Js.log(data))
  });
  ```