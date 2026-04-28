#include <exception>
#include <gtest/gtest.h>
#include <nlohmann/json.hpp>
#include <ntfy-lib/jsonFunc.hpp>

namespace {
    // Test OK cases for ntfy::json::stream_to_msg
    struct Param_stream_to_msg_OK {
        nlohmann::json input{};
        ntfy::Message expected{};
    };

    class F_in_out : public ::testing::TestWithParam<Param_stream_to_msg_OK> {};

    TEST_P(F_in_out, nothrow_and_match) {

        const auto param = GetParam();

        EXPECT_NO_THROW(ntfy::json::stream_to_msg(param.input));

        const ntfy::Message res = ntfy::json::stream_to_msg(param.input);
        ASSERT_EQ(res, param.expected) << "expected:\n" << param.expected.str() << "\nres:\n" << res.str();
    }

    INSTANTIATE_TEST_SUITE_P(stream_to_msg_OK, F_in_out,
                             ::testing::Values(
                                 // minimum members for OK json parsing
                                 Param_stream_to_msg_OK{.input = {{"event", "message"}, {"message", "example text"}},
                                                        .expected = {.content = "example text"}}));

    // Test THROW cases for ntfy::json::stream_to_msg

    TEST(stream_to_msg_THROWS, domain_error_on_missing_event) {
        ASSERT_THROW(ntfy::json::stream_to_msg({{"any", "json"}}), std::domain_error);
    }

    TEST(stream_to_msg_THROWS, runtime_error_on_missing_message) {
        ASSERT_THROW(ntfy::json::stream_to_msg({{"event", "message"}}), std::runtime_error);
    }
} // namespace