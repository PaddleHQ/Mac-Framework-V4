// swift-tools-version:5.3
import PackageDescription

let package = Package(
    name: "Paddle",
    platforms: [
        .macOS(.v10_13)
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
