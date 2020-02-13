# reason-node

## Project Status

This library is still under construction. Some of the core design details are still being ironed out. Therefore we cannot guarantee API stability at this time. We intend to achieve stability for most of the API very soon. We will make an announcement on the ReasonML [Discord channel](https://discord.gg/7MgaPKW) when we reach that goal.

----

## Installation

```shell
yarn install reason-nodejs
```

## Goal of this library

Help all Reason Node.js apps and libaries to be built faster by reducing the time spent on hand written bindings.

## Non-Goals

- Have 100% coverage of Node.js api surface - Due to lack of man power for testing and maintaining, we should only have enough surface
  to cover all common use cases. But we should have enough coverage that developers only rarely have to write a custom binding. 
- Ensure all APIs are idiomatic Reason and 100% typesafe - This library should be as barebones as possible to allow for minimal context switching between offical Node.js documentation and the Reason equilvalent. And due to the dynamic nature of the JS API, bending it to be idiomatic Reason will lead to a ton of bikeshedding in design as well as sacrificing maintainability.

## Principles

- When available, we prefer to bind to the promise version of the library instead of the callback version to reduce binding surface.
- Use subtyping only where the benefit is huge. We use subtyping for various APIs that implement Node Streams, such as HTTP Request and Response, FileSystem streams, Crypto streams, and etc. This allows us to use a single set of functions to manipulate and combine streams across different modules. For example:

  ### Stream a file into stdout:

  ```reason
    Fs.createReadStream("/path")
    ->Stream.pipe(Process.stdout)
    ->Stream.onError(_ => Js.log("handleError"))
  ```
  ### Echo server

  ```reason
  Http.createServer((request, response) => {
    request->Stream.onData(data => Js.log(data))
    request->Stream.pipe(response)->ignore
  });
  ```

## Contributing

We welcome and encourage anyone to contribute! In order to minimize confusion and avoid any wasted effort, here are some recommendations:

- If you notice a bug or a typo, feel free to create an issue or submit a PR to fix it.
- If you want to request a feature/improvement, it's best to create an issue first, so we can discuss the details. The last thing we want is for you to spend a lot of valuable time and energy creating a pull request when it doesn't fit in with the project goals. That doesn't mean we won't merge your PR, but we cannot guarantee it. We prioritize code review and open discussion.
- If you notice gaps in the documentation and want to help us fill in those gaps, you can help us out by submitting a PR, or by creating an issue and providing a draft of the docs you want to add.
- If you have concerns about our implementations or design decisions (e.g. type soundness, complexity, ergonomics, edge cases, etc.), you should submit an issue voicing your concerns. We gladly welcome critique from the community. We want this library to be as useful as possible, so we want to hear from you!
