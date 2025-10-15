defmodule AOC do
  def solve() do
    "input.txt"
    |> File.stream!()
    |> Stream.map(&process_line/1)
    |> Enum.count(& &1)
  end

  defp process_line(line) do
    line
    |> String.trim()
    |> String.split(" ")
    |> Enum.map(&String.to_integer/1)
    |> is_damper_safe()
  end

  defp is_damper_safe(list) do
    is_safe(list) or
      Enum.any?(0..(length(list) - 1), &is_safe(List.delete_at(list, &1)))
  end

  defp is_safe(list) do
    increasing_safe(list) or decreasing_safe(list)
  end

  defp increasing_safe([_]), do: true

  defp increasing_safe([a, b | tail]) when b - a > 0 and b - a <= 3,
    do: increasing_safe([b | tail])

  defp increasing_safe(_), do: false

  defp decreasing_safe([_]), do: true

  defp decreasing_safe([a, b | tail]) when a - b > 0 and a - b <= 3,
    do: decreasing_safe([b | tail])

  defp decreasing_safe(_), do: false
end

AOC.solve()
|> IO.inspect()
