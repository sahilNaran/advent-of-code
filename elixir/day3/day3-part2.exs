defmodule AOC do
  def solve() do
    "input.txt"
    |> File.read!()
    |> parse_mul_instructions()
  end

  defp parse_mul_instructions(input) do
    input
    |> parse_instructions([], true)
    |> Enum.sum()
  end

  defp parse_instructions(<<>>, results, _enabled), do: results
  defp parse_instructions("do()" <> rest, results, _enabled) do
    parse_instructions(rest, results, true)
  end
  defp parse_instructions("don't()" <> rest, results, _enabled) do
    parse_instructions(rest, results, false)
  end

  defp parse_instructions("mul(" <> rest, results, enabled) do
    case extract_mul_params(rest) do
      {:ok, x, y, remaining} ->
        if enabled do
          parse_instructions(remaining, [x * y | results], enabled)
        else
          parse_instructions(remaining, results, enabled)
        end
      :error -> parse_instructions(rest, results, enabled)
    end
  end

  defp parse_instructions(<<_::utf8, rest::binary>>, results, enabled) do
    parse_instructions(rest, results, enabled)
  end

  defp extract_mul_params(str) do
    case Integer.parse(str) do
      {num1, "," <> rest} when num1 in 1..999 ->
        case Integer.parse(rest) do
          {num2, ")" <> remaining} when num2 in 1..999 ->
            {:ok, num1, num2, remaining}

          _ ->
            :error
        end

      _ ->
        :error
    end
  end
end

AOC.solve()
|> IO.inspect()
