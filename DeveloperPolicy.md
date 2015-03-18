# Developer Policy #

This developer policy describes the guidelines and process of how to make contributions to MCLinker. The intent of the policy is to smooth the naturally distributed development process of the project and avoid possible miscommunication and unnecessary efforts.

The following describes the guidelines and review process.


## Guidelines ##

  1. When a developer begins a new major project with the intent to contribute it back to MCLinker, the developer should inform the other developers in the mail list. This is for all the developers to know the potential future directions of the MCLinker project and avoid possible duplication of the efforts on the same work.
  1. For submitting patches, a patch should have only one purpose and be kept as small as possible. Significant changes are required to be done as a series of incremental patches for the review process. This is to accelerate the review process. Developers should write down a simple description for purpose statement of the patch.
  1. All the patches should be submitted as the attachment of the mail, instead of being embedded in the text of the mail. This is to avoid any mangling during the mail delivering (e.g., making white space change).


## Review Process ##

Each change has three review stages:

#### Stage 1: <font color='#006666'>Submitting test cases with a purpose statement</font> ####

Developers should provide new unit test cases for the new features and state a simple purpose statement for the patch. Reviewers should verify that the patch fit the stated purpose.

#### Stage 2: <font color='#006666'>Submitting a scaffolding patch</font> ####

A Scaffolding patch contains just the class declarations and function interfaces, without any implementation details. Reviewers are responsible to make sure the creation/destruction relationships between classes are decent. Generally, how and when the classes are created/destroyed should be checked. The submitted scaffolding patch is expected to be compile-able, and run-able after committing it.

#### Stage 3: <font color='#006666'>Submitting an implementation patch</font> ####

After we run through the scaffolding stage, reviewers can quickly review the implementation patch. Reviewers are not necessarily required to spend much time reviewing the implementation, as the implementation passes the submitted test cases.