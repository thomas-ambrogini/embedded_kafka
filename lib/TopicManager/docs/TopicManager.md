# Topic Manager Documentation

## Description

The following is the documentation of the TopicManager part of the middleware

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Examples](#examples)
- [API Documentation](#api-documentation)
- [Contributing](#contributing)
- [License](#license)

## Installation

Instructions on how to install or set up the project. Include any prerequisites or dependencies that need to be installed.

## Usage

Instructions or guidelines on how to use the project or code. Provide examples or code snippets to showcase different features.

## Examples

Provide additional examples or use cases to demonstrate the functionality of the code or project.

## API Documentation

### TopicFactory

This class permits to build TopicProxy for the clients, simplifying their communication with the brokers, since it is handled by the TopicFactory.

#### Mehtods

##### TopicFactory(CommunicationType commType, const Logger &logger)

This constructor is used to simplify the testing in the unix part of the code, since it has in built knowledge about the Configurer endpoint information.

##### TopicFactory(CommunicationType commType, const Logger &logger, BrokerMetadata bootstrapBroker);

This constructor is used to specify the position of the Configurer (same as bootstrapBroker), making it more configurable.

## Contributing

Guidelines on how to contribute to the project, if applicable. Include instructions on reporting issues, suggesting improvements, or submitting pull requests.

## License

Specify the license under which the code is distributed. Include any copyright or license notices.

## Authors

List the authors or contributors to the code or project.

## Acknowledgments

Optionally, acknowledge any external resources, libraries, or references used in the project.
