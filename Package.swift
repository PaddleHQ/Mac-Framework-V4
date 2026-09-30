// swift-tools-version:5.5
import PackageDescription

let package = Package(
    name: "Paddle",
    platforms: [
        .macOS(.v12)
    ],
    products: [
        .library(
            name: "Paddle",
            targets: ["Paddle"])
    ],
    dependencies: [],
    targets: [
        .binaryTarget(
            name: "Paddle",
            path: "Paddle.xcframework")
    ]
)
