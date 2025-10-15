defmodule AOC do
  def solve() do
    "input.txt"
    |> File.stream!()
    |> Enum.map(fn line ->
      line
      |> String.replace("\n", "")
      |> String.split(" ")
      |> Enum.map(&String.to_integer/1)
      |> is_safe()
    end)
  end

  defp is_safe(list) do
    increasing_safe(list) or decreasing_safe(list)
  end

  defp increasing_safe([_]), do: true

  defp increasing_safe([a, b | tail]) when b - a > 0 and b - a <= 3,
    do: increasing_safe([b | tail])

  defp increasing_safe([]), do: true
  defp increasing_safe(_), do: false

  defp decreasing_safe([_]), do: true

  defp decreasing_safe([a, b | tail]) when a - b > 0 and a - b <= 3,
    do: decreasing_safe([b | tail])

  defp decreasing_safe([]), do: true
  defp decreasing_safe(_), do: false
end

result =
  AOC.solve()
  |> Enum.count(fn x -> x == true end)

IO.inspect(result)
